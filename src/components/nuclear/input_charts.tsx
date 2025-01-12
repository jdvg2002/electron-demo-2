import React, { useState, useEffect } from 'react';
import { LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, ResponsiveContainer } from 'recharts';
import { create, all } from 'mathjs';
import FillerView from '@/components/ui/filler';
import LoadingView from '@/components/ui/loading';
import type { ParseResult, Variable } from '@/types/engine';
import { Card } from '@/components/ui/card';

const math = create(all);

interface DataPoint {
    x: number;
    y: number;
}

type DistributionType = 'normal' | 'uniform' | 'exponential';

interface InputChartsProps {
    initialParseResult?: ParseResult | null;
}

function generateNormalDistribution(mean: number, stdDev: number, points: number = 100): DataPoint[] {
    const data: DataPoint[] = [];
    const range: number = 4 * stdDev;
    const step: number = range / points;
    
    for (let x: number = mean - range/2; x <= mean + range/2; x += step) {
        const y: number = (1 / (stdDev * Math.sqrt(2 * Math.PI))) * 
                 Math.exp(-Math.pow(x - mean, 2) / (2 * Math.pow(stdDev, 2)));
        data.push({ x, y });
    }
    return data;
}

function generateDistribution(value: number, uncertainty: number, type: DistributionType): DataPoint[] {
    switch (type) {
        case 'normal':
            return generateNormalDistribution(value, uncertainty);
        default:
            return generateNormalDistribution(value, uncertainty);
    }
}

function areVariablesEqual(prev: Variable[] | undefined, next: Variable[] | undefined): boolean {
    if (!prev && !next) return true;
    if (!prev || !next) return false;
    if (prev.length !== next.length) return false;
    
    return prev.every((prevVar, index) => {
        const nextVar = next[index];
        return prevVar.name === nextVar.name &&
               prevVar.value === nextVar.value &&
               prevVar.uncertainty === nextVar.uncertainty &&
               prevVar.distribution === nextVar.distribution &&
               prevVar.units === nextVar.units;
    });
}

const InputCharts: React.FC<InputChartsProps> = ({ initialParseResult = null }) => {
    const [isLoading, setIsLoading] = useState(false);
    const [parseResult, setParseResult] = useState<ParseResult | null>(initialParseResult);
    const colors = ['#8884d8', '#82ca9d', '#ffc658', '#ff7300', '#0088aa'];

    useEffect(() => {
        const handleParseResultsChanged = (event: CustomEvent<ParseResult | null>) => {
            const newResult = event.detail;
            if (!areVariablesEqual(newResult?.Variables, parseResult?.Variables)) {
                // When we get new variables, briefly show loading state
                if (newResult?.Variables && newResult.Variables.length > 0) {
                    setIsLoading(true);
                    // Simulate loading transition
                    setTimeout(() => setIsLoading(false), 500);
                }
                setParseResult(newResult);
            }
        };

        window.addEventListener('parseResultsChanged', handleParseResultsChanged as EventListener);

        return () => {
            window.removeEventListener('parseResultsChanged', handleParseResultsChanged as EventListener);
        };
    }, [parseResult?.Variables]);

    // Show loading state
    if (isLoading) {
        return <LoadingView message="Loading variables..." />;
    }

    // Show charts if we have valid variables
    if (parseResult?.Variables && parseResult.Variables.length > 0) {
        const formatNumber = (value: number): string => {
            if (Math.abs(value) < 10) {
                return value.toFixed(2);
            }
            return new Intl.NumberFormat('en-US').format(Math.round(value));
        };

        return (
            <div className="w-full h-full grid gap-4" style={{
                gridTemplateColumns: `repeat(${Math.min(parseResult.Variables.length, 3)}, 1fr)`,
                gridAutoRows: `minmax(0, ${100 / Math.ceil(parseResult.Variables.length / 3)}%)`
            }}>
                {parseResult.Variables.map((variable, index) => {
                    const data = generateDistribution(
                        variable.value,
                        variable.uncertainty,
                        variable.distribution as DistributionType
                    );
                    
                    return (
                        <Card key={`${variable.name}-${index}`} className="flex flex-col items-center p-2 bg-[#eaf9ff]">
                            <div className="text-center mb-2 p-1 rounded w-full">
                                <h2 className="text-sm font-semibold">
                                    {variable.name.charAt(0).toUpperCase() + variable.name.slice(1)}
                                </h2>
                                <div className="text-xs">
                                    μ={formatNumber(variable.value)} {variable.units}
                                    <br />
                                    σ={formatNumber(variable.uncertainty)} {variable.units}
                                </div>
                            </div>
                            <div className="h-[calc(100%-4rem)] w-full">
                                <ResponsiveContainer width="100%" height="100%">
                                    <LineChart 
                                        data={data}
                                        margin={{ top: 0, right: 0, bottom: -30, left: -60 }}
                                    >
                                        <XAxis 
                                            dataKey="x" 
                                            tick={false}
                                            domain={['dataMin', 'dataMax']}
                                        />
                                        <YAxis 
                                            tick={false} 
                                            domain={['auto', 'auto']}
                                        />
                                        <Line 
                                            type="monotone" 
                                            dataKey="y" 
                                            stroke={colors[index % colors.length]} 
                                            dot={false}
                                            strokeWidth={2}
                                        />
                                    </LineChart>
                                </ResponsiveContainer>
                            </div>
                        </Card>
                    );
                })}
            </div>
        );
    }

    // Default to filler view
    return <FillerView message="" />;
};

export default InputCharts;