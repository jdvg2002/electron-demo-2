<gov.sandia.chartreuse.type.model.PlotWindowModel>
  <uuid>daad2bf8-2d58-4f9a-8bdd-2a4046ecb055</uuid>
  <version>6.13</version>
  <name>Bar Chart - partial_correlations</name>
  <font>Segoe UI</font>
  <viewHeight>-1</viewHeight>
  <viewWidth>-1</viewWidth>
  <legendVisible>false</legendVisible>
  <canvasModels>
    <gov.sandia.chartreuse.type.model.PlotCanvasModel>
      <version>6.13</version>
      <rowPosition>0</rowPosition>
      <colPosition>0</colPosition>
      <axisPrecision>3</axisPrecision>
      <xAxisLabel></xAxisLabel>
      <yAxisLabel>response_fn_1</yAxisLabel>
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
          <version>6.13</version>
          <plotDataProviderObj class="gov.sandia.dakota.chartreuse.hdf.bridge.plotdata.DakotaHdfPlotDataProvider">
            <fileAbsPath>C:\Users\emridgw\dakota_gui_workspace\Sprint_2021-04\ChartreuseImportTest\hdf_examples\bar_charts\basic_lhs.h5</fileAbsPath>
            <hObjPath>/methods/NO_METHOD_ID/results/execution:1/partial_correlations</hObjPath>
            <lookupRelatedPlotData>true</lookupRelatedPlotData>
            <discreteStateSetVariable></discreteStateSetVariable>
          </plotDataProviderObj>
          <dimensionValues class="linked-hash-map">
            <entry>
              <int>1</int>
              <list>
                <string>nuv_1</string>
                <string>nuv_2</string>
                <string>uuv_1</string>
                <string>uuv_2</string>
              </list>
            </entry>
            <entry>
              <int>2</int>
              <list>
                <string>0.9045712114294531</string>
                <string>-0.14562353286266613</string>
                <string>0.054770757941505016</string>
                <string>0.06016607893396913</string>
              </list>
            </entry>
            <entry>
              <int>3</int>
              <list/>
            </entry>
          </dimensionValues>
          <dimensionLabels class="linked-hash-map">
            <entry>
              <int>2</int>
              <string>response_fn_1</string>
            </entry>
            <entry>
              <int>1</int>
              <string></string>
            </entry>
          </dimensionLabels>
          <properties>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_BOUND_UPPER</gov.sandia.chartreuse.type.PlotToken>
              <string>2147483647</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_POINT_TYPE</gov.sandia.chartreuse.type.PlotToken>
              <string>BAR_CHART</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_PRECISION</gov.sandia.chartreuse.type.PlotToken>
              <string>-1</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_DRAW_NUMBER_LABELS</gov.sandia.chartreuse.type.PlotToken>
              <string>true</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_ORIENTATION</gov.sandia.chartreuse.type.PlotToken>
              <string>Vertical</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_BOUND_LOWER</gov.sandia.chartreuse.type.PlotToken>
              <string>-2147483648</string>
            </entry>
            <entry>
              <gov.sandia.chartreuse.type.PlotToken>TRACE_POINT_MODE</gov.sandia.chartreuse.type.PlotToken>
              <string>Circle</string>
            </entry>
          </properties>
          <rgbs>
            <org.eclipse.swt.graphics.RGB>
              <red>179</red>
              <green>179</green>
              <blue>217</blue>
            </org.eclipse.swt.graphics.RGB>
          </rgbs>
          <colorScaleAnchors>
            <double>0.0</double>
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