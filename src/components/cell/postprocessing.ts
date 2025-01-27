interface DataPoint {
  T: number;
  sigma_f: number;
}

export const processStressData = (dataArray: DataPoint[]) => {
  // Extract T and sigma_f values
  const T = dataArray.map(d => d.T);
  const sigma_f = dataArray.map(d => d.sigma_f);
  
  // Find global min and max
  const allValues = [...T, ...sigma_f];
  const globalMin = Math.min(...allValues);
  const globalMax = Math.max(...allValues);
  
  // Calculate KDE for both distributions
  const points = 200;
  const x = Array.from({length: points}, (_, i) => 
    globalMin + (i * (globalMax - globalMin) / (points-1))
  );
  
  const calculateDensity = (data: number[]) => {
    const mean = data.reduce((a, b) => a + b) / data.length;
    const variance = data.reduce((a, b) => a + Math.pow(b - mean, 2), 0) / data.length;
    const h = Math.sqrt(variance) * Math.pow(data.length, -0.2) * 3.0;
    
    return x.map(xi => {
      const density = data.map(d => 
        Math.exp(-0.5 * Math.pow((xi - d) / h, 2)) / (h * Math.sqrt(2 * Math.PI))
      ).reduce((a, b) => a + b) / data.length;
      return density;
    });
  };

  const T_density = calculateDensity(T);
  const sigma_f_density = calculateDensity(sigma_f);
  
  // Normalize densities
  const dx = x[1] - x[0];
  const normalizeData = (density: number[]) => {
    const integral = density.reduce((sum, y, i) => {
      if (i === 0 || i === density.length - 1) return sum + y * dx / 2;
      return sum + y * dx;
    }, 0);
    return density.map(d => d / integral);
  };

  const T_normalized = normalizeData(T_density);
  const sigma_f_normalized = normalizeData(sigma_f_density);

  // Create chart data
  const chartData = x.map((xi, i) => ({
    x: xi,
    appliedStress: T_normalized[i],
    flowStress: sigma_f_normalized[i]
  }));

  // Calculate probability of failure
  const failureCount = dataArray.filter(d => d.T > d.sigma_f).length;
  const pof = failureCount / dataArray.length;

  return {
    chartData,
    probabilityOfFailure: pof
  };
};
