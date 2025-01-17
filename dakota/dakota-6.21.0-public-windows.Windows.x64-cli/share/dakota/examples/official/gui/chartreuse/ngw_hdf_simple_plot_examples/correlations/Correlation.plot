<gov.sandia.chartreuse.type.model.PlotWindowModel>
  <uuid>b3e9e859-e2df-4f72-8a0d-5d29dc3f12c9</uuid>
  <version>6.14</version>
  <name>PartialCorrelation</name>
  <font>Segoe UI</font>
  <viewHeight>-1</viewHeight>
  <viewWidth>-1</viewWidth>
  <legendVisible>false</legendVisible>
  <canvasModels>
    <gov.sandia.chartreuse.type.model.PlotCanvasModel>
      <version>6.14</version>
      <name>PartialCorrelation</name>
      <rowPosition>0</rowPosition>
      <colPosition>0</colPosition>
      <axisPrecision>3</axisPrecision>
      <xAxisLabel></xAxisLabel>
      <yAxisLabel></yAxisLabel>
      <zAxisLabel></zAxisLabel>
      <xAxisRGB>
        <red>0</red>
        <green>0</green>
        <blue>0</blue>
      </xAxisRGB>
      <yAxisRGB>
        <red>0</red>
        <green>0</green>
        <blue>0</blue>
      </yAxisRGB>
      <zAxisRGB>
        <red>0</red>
        <green>0</green>
        <blue>0</blue>
      </zAxisRGB>
      <xAxisRangeStart>-Infinity</xAxisRangeStart>
      <xAxisRangeEnd>Infinity</xAxisRangeEnd>
      <yAxisRangeStart>-Infinity</yAxisRangeStart>
      <yAxisRangeEnd>Infinity</yAxisRangeEnd>
      <zAxisRangeStart>-Infinity</zAxisRangeStart>
      <zAxisRangeEnd>Infinity</zAxisRangeEnd>
      <autoscale>true</autoscale>
      <xLogScale>false</xLogScale>
      <yLogScale>false</yLogScale>
      <zLogScale>false</zLogScale>
      <drawGridLines>true</drawGridLines>
      <drawAxisLines>true</drawAxisLines>
      <parent reference="../../.."/>
      <overlaidCanvasModels/>
      <traceModels>
        <gov.sandia.chartreuse.type.model.PlotTraceModel>
          <version>6.14</version>
          <name>PartialCorrelation</name>
          <plotDataProviderObj class="gov.sandia.dakota.chartreuse.hdf.bridge.plotdata.DakotaHdfPlotDataProvider">
            <fileAbsPath>C:\Users\emridgw\dakota_gui_workspace\Sprint_2021_10\NewExamples\ngw_hdf_simple_plot_examples\correlations\increm_lhs.h5</fileAbsPath>
            <hObjPath>/methods/NO_METHOD_ID/results/execution:1/increment:3/partial_correlations</hObjPath>
            <lookupRelatedPlotData>false</lookupRelatedPlotData>
            <discreteStateSetVariable></discreteStateSetVariable>
            <modelId></modelId>
            <interfaceId></interfaceId>
          </plotDataProviderObj>
          <dimensionValues class="linked-hash-map">
            <entry>
              <int>1</int>
              <list>
                <string>nuv_1</string>
                <string>nuv_1</string>
                <string>nuv_2</string>
                <string>nuv_2</string>
                <string>uuv_1</string>
                <string>uuv_1</string>
                <string>uuv_2</string>
                <string>uuv_2</string>
              </list>
            </entry>
            <entry>
              <int>2</int>
              <list>
                <string>response_fn_1</string>
                <string>response_fn_2</string>
                <string>response_fn_1</string>
                <string>response_fn_2</string>
                <string>response_fn_1</string>
                <string>response_fn_2</string>
                <string>response_fn_1</string>
                <string>response_fn_2</string>
              </list>
            </entry>
            <entry>
              <int>3</int>
              <list>
                <string>0.9171559373013515</string>
                <string>0.9899494317635165</string>
                <string>-0.04041142652466489</string>
                <string>-0.12220026544416392</string>
                <string>0.03695546155326736</string>
                <string>0.024759562361433535</string>
                <string>-0.06589066847020358</string>
                <string>-0.07042949696122938</string>
              </list>
            </entry>
          </dimensionValues>
          <dimensionLabels class="linked-hash-map">
            <entry>
              <int>1</int>
              <string></string>
            </entry>
            <entry>
              <int>2</int>
              <string></string>
            </entry>
            <entry>
              <int>3</int>
              <string></string>
            </entry>
          </dimensionLabels>
          <properties>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_BOUND_UPPER</gov.sandia.chartreuse.type.PlotToken>
              <string>2147483647</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_BOUND_LOWER</gov.sandia.chartreuse.type.PlotToken>
              <string>-2147483648</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_DRAW_NUMBER_LABELS</gov.sandia.chartreuse.type.PlotToken>
              <string>true</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_PRECISION</gov.sandia.chartreuse.type.PlotToken>
              <string>3</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_POINT_TYPE</gov.sandia.chartreuse.type.PlotToken>
              <string>HEAT_MAP_CATEGORICAL</string>
            </entry>
          </properties>
          <rgbs>
            <org.eclipse.swt.graphics.RGB>
              <red>85</red>
              <green>72</green>
              <blue>193</blue>
            </org.eclipse.swt.graphics.RGB>
            <org.eclipse.swt.graphics.RGB>
              <red>242</red>
              <green>242</green>
              <blue>242</blue>
            </org.eclipse.swt.graphics.RGB>
            <org.eclipse.swt.graphics.RGB>
              <red>177</red>
              <green>1</green>
              <blue>39</blue>
            </org.eclipse.swt.graphics.RGB>
          </rgbs>
          <colorScaleAnchors>
            <double>-1.0</double>
            <double>0.0</double>
            <double>1.0</double>
          </colorScaleAnchors>
          <colorScaleType>Continuous</colorScaleType>
          <trimNoDelta>NONE</trimNoDelta>
          <relativeAxis>NONE</relativeAxis>
          <parent reference="../../.."/>
        </gov.sandia.chartreuse.type.model.PlotTraceModel>
      </traceModels>
    </gov.sandia.chartreuse.type.model.PlotCanvasModel>
  </canvasModels>
</gov.sandia.chartreuse.type.model.PlotWindowModel>