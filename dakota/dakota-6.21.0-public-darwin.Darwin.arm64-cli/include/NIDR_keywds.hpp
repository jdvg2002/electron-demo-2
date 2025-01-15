
namespace Dakota {

static KeyWord
	kw_1[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_stm(augment_utype,postRunInputFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_stm(augment_utype,postRunInputFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_stm(augment_utype,postRunInputFormat_TABULAR_IFACE_ID)}
		},
	kw_2[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_stm(utype,postRunInputFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1,0.,0.,0,N_stm(utype,postRunInputFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_stm(utype,postRunInputFormat_TABULAR_NONE)}
		},
	kw_3[2] = {
		{"input",11,3,1,0,kw_2,0.,0.,0,N_stm(str,postRunInput)},
		{"output",11,0,2,0,0,0.,0.,0,N_stm(str,postRunOutput)}
		},
	kw_4[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_stm(augment_utype,preRunOutputFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_stm(augment_utype,preRunOutputFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_stm(augment_utype,preRunOutputFormat_TABULAR_IFACE_ID)}
		},
	kw_5[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_stm(utype,preRunOutputFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_4,0.,0.,0,N_stm(utype,preRunOutputFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_stm(utype,preRunOutputFormat_TABULAR_NONE)}
		},
	kw_6[2] = {
		{"input",11,0,1,0,0,0.,0.,0,N_stm(str,preRunInput)},
		{"output",11,3,2,0,kw_5,0.,0.,0,N_stm(str,preRunOutput)}
		},
	kw_7[1] = {
		{"stop_restart",0x29,0,1,0,0,0.,0.,0,N_stm(int,stopRestart)}
		},
	kw_8[3] = {
		{"all",8,0,1,1,0,0.,0.,0,N_stm(utype,interfEvalsSelection_INTERF_EVAL_STORE_ALL)},
		{"none",8,0,1,1,0,0.,0.,0,N_stm(utype,interfEvalsSelection_INTERF_EVAL_STORE_NONE)},
		{"simulation",8,0,1,1,0,0.,0.,0,N_stm(utype,interfEvalsSelection_INTERF_EVAL_STORE_SIMULATION)}
		},
	kw_9[4] = {
		{"all",8,0,1,1,0,0.,0.,0,N_stm(utype,modelEvalsSelection_MODEL_EVAL_STORE_ALL)},
		{"all_methods",8,0,1,1,0,0.,0.,0,N_stm(utype,modelEvalsSelection_MODEL_EVAL_STORE_ALL_METHODS)},
		{"none",8,0,1,1,0,0.,0.,0,N_stm(utype,modelEvalsSelection_MODEL_EVAL_STORE_NONE)},
		{"top_method",8,0,1,1,0,0.,0.,0,N_stm(utype,modelEvalsSelection_MODEL_EVAL_STORE_TOP_METHOD)}
		},
	kw_10[2] = {
		{"interface_selection",8,3,2,0,kw_8},
		{"model_selection",8,4,1,0,kw_9}
		},
	kw_11[3] = {
		{"hdf5",8,2,3,0,kw_10,0.,0.,0,N_stm(augment_utype,resultsOutputFormat_RESULTS_OUTPUT_HDF5)},
		{"results_output_file",11,0,1,0,0,0.,0.,0,N_stm(str,resultsOutputFile)},
		{"text",8,0,2,0,0,0.,0.,0,N_stm(augment_utype,resultsOutputFormat_RESULTS_OUTPUT_TEXT)}
		},
	kw_12[2] = {
		{"input",11,0,1,0,0,0.,0.,0,N_stm(str,runInput)},
		{"output",11,0,2,0,0,0.,0.,0,N_stm(str,runOutput)}
		},
	kw_13[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_stm(augment_utype,tabularFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_stm(augment_utype,tabularFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_stm(augment_utype,tabularFormat_TABULAR_IFACE_ID)}
		},
	kw_14[5] = {
		{"annotated",8,0,2,0,0,0.,0.,0,N_stm(utype,tabularFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,2,0,kw_13,0.,0.,0,N_stm(utype,tabularFormat_TABULAR_NONE)},
		{"freeform",8,0,2,0,0,0.,0.,0,N_stm(utype,tabularFormat_TABULAR_NONE)},
		{"tabular_data_file",11,0,1,0,0,0.,0.,0,N_stm(str,tabularDataFile)},
		{"tabular_graphics_file",3,0,1,0,0,0.,0.,-1,N_stm(str,tabularDataFile)}
		},
	kw_15[15] = {
		{"check",8,0,9,0,0,0.,0.,0,N_stm(true,checkFlag)},
		{"error_file",11,0,3,0,0,0.,0.,0,N_stm(str,errorFile)},
		{"graphics",8,0,8,0,0,0.,0.,0,N_stm(true,graphicsFlag)},
		{"method_pointer",3,0,13,0,0,0.,0.,10,N_stm(str,topMethodPointer)},
		{"output_file",11,0,2,0,0,0.,0.,0,N_stm(str,outputFile)},
		{"output_precision",0x29,0,6,0,0,0.,0.,0,N_stm(int,outputPrecision)},
		{"post_run",8,2,12,0,kw_3,0.,0.,0,N_stm(true,postRunFlag)},
		{"pre_run",8,2,10,0,kw_6,0.,0.,0,N_stm(true,preRunFlag)},
		{"read_restart",11,1,4,0,kw_7,0.,0.,0,N_stm(str,readRestart)},
		{"results_output",8,3,7,0,kw_11,0.,0.,0,N_stm(true,resultsOutputFlag)},
		{"run",8,2,11,0,kw_12,0.,0.,0,N_stm(true,runFlag)},
		{"tabular_data",8,5,1,0,kw_14,0.,0.,0,N_stm(true,tabularDataFlag)},
		{"tabular_graphics_data",0,5,1,0,kw_14,0.,0.,-1,N_stm(true,tabularDataFlag)},
		{"top_method_pointer",11,0,13,0,0,0.,0.,0,N_stm(str,topMethodPointer)},
		{"write_restart",11,0,5,0,0,0.,0.,0,N_stm(str,writeRestart)}
		},
	kw_16[1] = {
		{"processors_per_analysis",0x19,0,1,0,0,0.,0.,0,N_ifm(int,procsPerAnalysis)}
		},
	kw_17[3] = {
		{"aprepro",8,0,1,1,0,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_APREPRO)},
		{"json",8,0,1,1,0,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_JSON)},
		{"standard",8,0,1,1,0,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_STANDARD)}
		},
	kw_18[1] = {
		{"labeled",8,0,1,0,0,0.,0.,0,N_ifm(true,dakotaResultsFileLabeled)}
		},
	kw_19[2] = {
		{"json",8,0,1,1,0,0.,0.,0,N_ifm(type,resultsFileFormat_RESULTS_FILE_JSON)},
		{"standard",8,1,1,1,kw_18,0.,0.,0,N_ifm(type,resultsFileFormat_RESULTS_FILE_STANDARD)}
		},
	kw_20[8] = {
		{"copy_files",15,0,5,0,0,0.,0.,0,N_ifm(strL,copyFiles)},
		{"dir_save",0,0,3,0,0,0.,0.,2,N_ifm(true,dirSave)},
		{"dir_tag",0,0,2,0,0,0.,0.,2,N_ifm(true,dirTag)},
		{"directory_save",8,0,3,0,0,0.,0.,0,N_ifm(true,dirSave)},
		{"directory_tag",8,0,2,0,0,0.,0.,0,N_ifm(true,dirTag)},
		{"link_files",15,0,4,0,0,0.,0.,0,N_ifm(strL,linkFiles)},
		{"named",11,0,1,0,0,0.,0.,0,N_ifm(str,workDir)},
		{"replace",8,0,6,0,0,0.,0.,0,N_ifm(true,templateReplace)}
		},
	kw_21[9] = {
		{"allow_existing_results",8,0,8,0,0,0.,0.,0,N_ifm(true,allowExistingResultsFlag)},
		{"file_save",8,0,6,0,0,0.,0.,0,N_ifm(true,fileSaveFlag)},
		{"file_tag",8,0,5,0,0,0.,0.,0,N_ifm(true,fileTagFlag)},
		{"parameters_file",11,0,1,0,0,0.,0.,0,N_ifm(str,parametersFile)},
		{"parameters_format",8,3,3,0,kw_17,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_STANDARD)},
		{"results_file",11,0,2,0,0,0.,0.,0,N_ifm(str,resultsFile)},
		{"results_format",8,2,4,0,kw_19,0.,0.,0,N_ifm(type,resultsFileFormat_RESULTS_FILE_STANDARD)},
		{"verbatim",8,0,9,0,0,0.,0.,0,N_ifm(true,verbatimFlag)},
		{"work_directory",8,8,7,0,kw_20,0.,0.,0,N_ifm(true,useWorkdir)}
		},
	kw_22[1] = {
		{"numpy",8,0,1,0,0,0.,0.,0,N_ifm(true,numpyFlag)}
		},
	kw_23[1] = {
		{"library_path",11,0,1,1,0,0.,0.,0,N_ifm(str,pluginLibraryPath)}
		},
	kw_24[1] = {
		{"numpy",8,0,1,0,0,0.,0.,0,N_ifm(true,numpyFlag)}
		},
	kw_25[3] = {
		{"aprepro",8,0,1,1,0,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_APREPRO)},
		{"json",8,0,1,1,0,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_JSON)},
		{"standard",8,0,1,1,0,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_STANDARD)}
		},
	kw_26[1] = {
		{"labeled",8,0,1,0,0,0.,0.,0,N_ifm(true,dakotaResultsFileLabeled)}
		},
	kw_27[2] = {
		{"json",8,0,1,1,0,0.,0.,0,N_ifm(type,resultsFileFormat_RESULTS_FILE_JSON)},
		{"standard",8,1,1,1,kw_26,0.,0.,0,N_ifm(type,resultsFileFormat_RESULTS_FILE_STANDARD)}
		},
	kw_28[8] = {
		{"copy_files",15,0,5,0,0,0.,0.,0,N_ifm(strL,copyFiles)},
		{"dir_save",0,0,3,0,0,0.,0.,2,N_ifm(true,dirSave)},
		{"dir_tag",0,0,2,0,0,0.,0.,2,N_ifm(true,dirTag)},
		{"directory_save",8,0,3,0,0,0.,0.,0,N_ifm(true,dirSave)},
		{"directory_tag",8,0,2,0,0,0.,0.,0,N_ifm(true,dirTag)},
		{"link_files",15,0,4,0,0,0.,0.,0,N_ifm(strL,linkFiles)},
		{"named",11,0,1,0,0,0.,0.,0,N_ifm(str,workDir)},
		{"replace",8,0,6,0,0,0.,0.,0,N_ifm(true,templateReplace)}
		},
	kw_29[9] = {
		{"allow_existing_results",8,0,8,0,0,0.,0.,0,N_ifm(true,allowExistingResultsFlag)},
		{"file_save",8,0,6,0,0,0.,0.,0,N_ifm(true,fileSaveFlag)},
		{"file_tag",8,0,5,0,0,0.,0.,0,N_ifm(true,fileTagFlag)},
		{"parameters_file",11,0,1,0,0,0.,0.,0,N_ifm(str,parametersFile)},
		{"parameters_format",8,3,3,0,kw_25,0.,0.,0,N_ifm(type,parametersFileFormat_PARAMETERS_FILE_STANDARD)},
		{"results_file",11,0,2,0,0,0.,0.,0,N_ifm(str,resultsFile)},
		{"results_format",8,2,4,0,kw_27,0.,0.,0,N_ifm(type,resultsFileFormat_RESULTS_FILE_STANDARD)},
		{"verbatim",8,0,9,0,0,0.,0.,0,N_ifm(true,verbatimFlag)},
		{"work_directory",8,8,7,0,kw_28,0.,0.,0,N_ifm(true,useWorkdir)}
		},
	kw_30[12] = {
		{"analysis_components",15,0,4,0,0,0.,0.,0,N_ifm(str2D,analysisComponents)},
		{"direct",8,1,3,1,kw_16,0.,0.,0,N_ifm(type,interfaceType_TEST_INTERFACE)},
		{"fork",8,9,3,1,kw_21,0.,0.,0,N_ifm(type,interfaceType_FORK_INTERFACE)},
		{"grid",8,0,3,1,0,0.,0.,0,N_ifm(type,interfaceType_GRID_INTERFACE)},
		{"input_filter",11,0,1,0,0,0.,0.,0,N_ifm(str,inputFilter)},
		{"legacy_python",8,1,3,1,kw_22,0.,0.,0,N_ifm(type,interfaceType_LEGACY_PYTHON_INTERFACE)},
		{"matlab",8,0,3,1,0,0.,0.,0,N_ifm(type,interfaceType_MATLAB_INTERFACE)},
		{"output_filter",11,0,2,0,0,0.,0.,0,N_ifm(str,outputFilter)},
		{"plugin",8,1,3,1,kw_23,0.,0.,0,N_ifm(type,interfaceType_PLUGIN_INTERFACE)},
		{"python",8,1,3,1,kw_24,0.,0.,0,N_ifm(type,interfaceType_PYTHON_INTERFACE)},
		{"scilab",8,0,3,1,0,0.,0.,0,N_ifm(type,interfaceType_SCILAB_INTERFACE)},
		{"system",8,9,3,1,kw_29,0.,0.,0,N_ifm(type,interfaceType_SYSTEM_INTERFACE)}
		},
	kw_31[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_ifm(type,analysisScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_ifm(type,analysisScheduling_PEER_SCHEDULING)}
		},
	kw_32[2] = {
		{"dynamic",8,0,1,1,0,0.,0.,0,N_ifm(type,asynchLocalEvalScheduling_DYNAMIC_SCHEDULING)},
		{"static",8,0,1,1,0,0.,0.,0,N_ifm(type,asynchLocalEvalScheduling_STATIC_SCHEDULING)}
		},
	kw_33[3] = {
		{"analysis_concurrency",0x19,0,3,0,0,0.,0.,0,N_ifm(int,asynchLocalAnalysisConcurrency)},
		{"evaluation_concurrency",0x19,0,1,0,0,0.,0.,0,N_ifm(int,asynchLocalEvalConcurrency)},
		{"local_evaluation_scheduling",8,2,2,0,kw_32}
		},
	kw_34[1] = {
		{"size",0x19,0,1,0,0,0.,0.,0,N_ifm(int,asynchLocalEvalConcurrency)}
		},
	kw_35[1] = {
		{"cache_tolerance",10,0,1,0,0,0.,0.,0,N_ifm(Real,nearbyEvalCacheTol)}
		},
	kw_36[4] = {
		{"active_set_vector",8,0,1,0,0,0.,0.,0,N_ifm(false,activeSetVectorFlag)},
		{"evaluation_cache",8,0,2,0,0,0.,0.,0,N_ifm(false,evalCacheFlag)},
		{"restart_file",8,0,4,0,0,0.,0.,0,N_ifm(false,restartFileFlag)},
		{"strict_cache_equality",8,1,3,0,kw_35,0.,0.,0,N_ifm(true,nearbyEvalCacheFlag)}
		},
	kw_37[2] = {
		{"dynamic",8,0,1,1,0,0.,0.,0,N_ifm(type,evalScheduling_PEER_DYNAMIC_SCHEDULING)},
		{"static",8,0,1,1,0,0.,0.,0,N_ifm(type,evalScheduling_PEER_STATIC_SCHEDULING)}
		},
	kw_38[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_ifm(type,evalScheduling_MASTER_SCHEDULING)},
		{"peer",8,2,1,1,kw_37}
		},
	kw_39[4] = {
		{"abort",8,0,1,1,0,0.,0.,0,N_ifm(lit,failAction_abort)},
		{"continuation",8,0,1,1,0,0.,0.,0,N_ifm(lit,failAction_continuation)},
		{"recover",14,0,1,1,0,0.,0.,0,N_ifm(Rlit,TYPE_DATA_failAction_recover)},
		{"retry",9,0,1,1,0,0.,0.,0,N_ifm(ilit,TYPE_DATA_failAction_retry)}
		},
	kw_40[12] = {
		{"algebraic_mappings",11,0,3,0,0,0.,0.,0,N_ifm(str,algebraicMappings)},
		{"analysis_drivers",15,12,2,0,kw_30,0.,0.,0,N_ifm(strL,analysisDrivers)},
		{"analysis_scheduling",8,2,11,0,kw_31},
		{"analysis_servers",0x19,0,10,0,0,0.,0.,0,N_ifm(int,analysisServers)},
		{"asynchronous",8,3,6,0,kw_33,0.,0.,0,N_ifm(true, asynchFlag)},
		{"batch",8,1,6,0,kw_34,0.,0.,0,N_ifm(true,batchEvalFlag)},
		{"deactivate",8,4,5,0,kw_36},
		{"evaluation_scheduling",8,2,8,0,kw_38},
		{"evaluation_servers",0x19,0,7,0,0,0.,0.,0,N_ifm(int,evalServers)},
		{"failure_capture",8,4,4,0,kw_39},
		{"id_interface",11,0,1,0,0,0.,0.,0,N_ifm(str,idInterface)},
		{"processors_per_evaluation",0x19,0,9,0,0,0.,0.,0,N_ifm(int,procsPerEval)}
		},
	kw_41[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_42[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_41,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_43[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_44[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_45[1] = {
		{"depth_limit",9,0,1,1,0,0.,0.,0,N_mdm(ushint,dagDepthLimit)}
		},
	kw_46[5] = {
		{"full_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_FULL_GRAPH_RECURSION)},
		{"kl_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_KL_GRAPH_RECURSION)},
		{"model_selection",8,0,1,0,0,0.,0.,0,N_mdm(type,modelSelectType_ALL_MODEL_COMBINATIONS)},
		{"no_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_NO_GRAPH_RECURSION)},
		{"partial_recursion",8,1,2,1,kw_45,0.,0.,0,N_mdm(type,dagRecursionType_PARTIAL_GRAPH_RECURSION)}
		},
	kw_47[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_48[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_49[2] = {
		{"distribution",8,2,2,0,kw_47},
		{"final_moments",8,3,1,0,kw_48}
		},
	kw_50[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_49,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_51[1] = {
		{"final_statistics",8,2,1,0,kw_50}
		},
	kw_52[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_53[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_54[2] = {
		{"distribution",8,2,2,0,kw_52},
		{"final_moments",8,3,1,0,kw_53}
		},
	kw_55[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_54,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_56[3] = {
		{"factor_sequence",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,relaxFactorSequence)},
		{"fixed_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxFixedFactor)},
		{"recursive_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxRecursiveFactor)}
		},
	kw_57[2] = {
		{"final_statistics",8,2,2,0,kw_55},
		{"relaxation",8,3,1,0,kw_56}
		},
	kw_58[4] = {
		{"offline_pilot",8,1,1,1,kw_51,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT)},
		{"offline_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT_PROJECTION)},
		{"online_pilot",8,2,1,1,kw_57,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT)},
		{"online_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT_PROJECTION)}
		},
	kw_59[24] = {
		{"acv_independent_sampling",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_ACV_IS)},
		{"acv_is",0,0,1,1,0,0.,0.,-1,N_mdm(utype,subMethod_SUBMETHOD_ACV_IS)},
		{"acv_mf",0,0,1,1,0,0.,0.,1,N_mdm(utype,subMethod_SUBMETHOD_ACV_MF)},
		{"acv_multifidelity",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_ACV_MF)},
		{"acv_rd",0,0,1,1,0,0.,0.,1,N_mdm(utype,subMethod_SUBMETHOD_ACV_RD)},
		{"acv_recursive_diff",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_ACV_RD)},
		{"competed_local",8,0,6,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL_OPTPP)},
		{"convergence_tolerance",10,0,11,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"export_sample_sequence",8,3,10,0,kw_42,0.,0.,0,N_mdm(true,exportSampleSeqFlag)},
		{"fixed_seed",8,0,8,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"global_local",8,0,6,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_DIRECT_NPSOL_OPTPP)},
		{"initial_samples",5,0,3,0,0,0.,0.,5,N_mdm(szarray,pilotSamples)},
		{"max_function_evaluations",0x29,0,13,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,12,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,15,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"nip",8,0,6,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"pilot_samples",13,0,3,0,0,0.,0.,0,N_mdm(szarray,pilotSamples)},
		{"rng",8,2,14,0,kw_43},
		{"sample_type",8,2,9,0,kw_44},
		{"search_model_graphs",8,5,2,0,kw_46},
		{"seed_sequence",13,0,7,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solution_mode",8,4,4,0,kw_58},
		{"sqp",8,0,6,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)},
		{"truth_fixed_by_pilot",8,0,5,0,0,0.,0.,0,N_mdm(true,truthPilotConstraint)}
		},
	kw_60[4] = {
		{"constant_liar",8,0,1,1,0,0.,0.,0,N_mdm(lit,batchSelectionType_cl)},
		{"distance_penalty",8,0,1,1,0,0.,0.,0,N_mdm(lit,batchSelectionType_distance)},
		{"naive",8,0,1,1,0,0.,0.,0,N_mdm(lit,batchSelectionType_naive)},
		{"topology",8,0,1,1,0,0.,0.,0,N_mdm(lit,batchSelectionType_topology)}
		},
	kw_61[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_62[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_63[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_62,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_64[3] = {
		{"distance",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessMetricType_distance)},
		{"gradient",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessMetricType_gradient)},
		{"predicted_variance",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessMetricType_predicted_variance)}
		},
	kw_65[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_66[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_67[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_66,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_68[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_69[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_70[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_69}
		},
	kw_71[2] = {
		{"compute",8,3,2,0,kw_70},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_72[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_73[19] = {
		{"batch_selection",8,4,5,0,kw_60},
		{"distribution",8,2,14,0,kw_61},
		{"export_approx_points_file",11,3,8,0,kw_63,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,8,0,kw_63,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"fitness_metric",8,3,4,0,kw_64},
		{"gen_reliability_levels",14,1,13,0,kw_65,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_build_points_file",11,4,7,0,kw_67,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,7,0,kw_67,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"initial_samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"max_iterations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,9,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,16,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,12,0,kw_68,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"refinement_samples",13,0,6,0,0,0.,0.,0,N_mdm(ivec,refineSamples)},
		{"response_levels",14,2,11,0,kw_71,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,15,0,kw_72},
		{"samples",1,0,1,0,0,0.,0.,-8,N_mdm(int,numSamples)},
		{"samples_on_emulator",9,0,3,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_74[7] = {
		{"merit1",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit1)},
		{"merit1_smooth",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit1_smooth)},
		{"merit2",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit2)},
		{"merit2_smooth",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit2_smooth)},
		{"merit2_squared",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit2_squared)},
		{"merit_max",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit_max)},
		{"merit_max_smooth",8,0,1,1,0,0.,0.,0,N_mdm(lit,meritFunction_merit_max_smooth)}
		},
	kw_75[2] = {
		{"blocking",8,0,1,1,0,0.,0.,0,N_mdm(type,evalSynchronize_BLOCKING_SYNCHRONIZATION)},
		{"nonblocking",8,0,1,1,0,0.,0.,0,N_mdm(type,evalSynchronize_NONBLOCKING_SYNCHRONIZATION)}
		},
	kw_76[13] = {
		{"constraint_penalty",10,0,7,0,0,0.,0.,0,N_mdm(Real,constrPenalty)},
		{"constraint_tolerance",10,0,9,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"contraction_factor",10,0,2,0,0,0.,0.,0,N_mdm(Real,contractStepLength)},
		{"initial_delta",10,0,1,0,0,0.,0.,0,N_mdm(Real,initStepLength)},
		{"max_function_evaluations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"merit_function",8,7,6,0,kw_74},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,11,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"smoothing_factor",10,0,8,0,0,0.,0.,0,N_mdm(Real,smoothFactor)},
		{"solution_accuracy",2,0,4,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,4,0,0,0.,0.,0,N_mdm(Real,solnTarget)},
		{"synchronization",8,2,5,0,kw_75},
		{"variable_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,threshStepLength)}
		},
	kw_77[1] = {
		{"hyperprior_betas",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,hyperPriorBetas)}
		},
	kw_78[5] = {
		{"both",8,0,1,1,0,0.,0.,0,N_mdm(utype,calibrateErrorMode_CALIBRATE_BOTH)},
		{"hyperprior_alphas",14,1,2,0,kw_77,0.,0.,0,N_mdm(RealDL,hyperPriorAlphas)},
		{"one",8,0,1,1,0,0.,0.,0,N_mdm(utype,calibrateErrorMode_CALIBRATE_ONE)},
		{"per_experiment",8,0,1,1,0,0.,0.,0,N_mdm(utype,calibrateErrorMode_CALIBRATE_PER_EXPER)},
		{"per_response",8,0,1,1,0,0.,0.,0,N_mdm(utype,calibrateErrorMode_CALIBRATE_PER_RESP)}
		},
	kw_79[1] = {
		{"confidence_intervals",8,0,1,0,0,0.,0.,0,N_mdm(true,chainDiagnosticsCI)}
		},
	kw_80[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_81[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_80,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_82[6] = {
		{"build_samples",9,0,2,0,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"import_build_points_file",11,4,4,0,kw_81,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_81,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,3,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)},
		{"surfpack",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_83[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_84[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_85[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_86[3] = {
		{"adapted",8,2,1,1,kw_85,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_87[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_88[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_89[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_90[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_91[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_92[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_93[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_87,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_87,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_88,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_89,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_90,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_90,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_89,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_91,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_92,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_92,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_94[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_95[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_96[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_95,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_97[6] = {
		{"basis_type",8,3,2,0,kw_86},
		{"collocation_ratio",10,21,3,1,kw_93,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_94,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_96,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_96,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_98[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_99[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_98,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_100[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_99,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_99,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_101[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_102[2] = {
		{"dimension_adaptive",8,3,1,1,kw_101},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_103[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_104[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_105[16] = {
		{"allocation_control",8,1,3,0,kw_83},
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,9,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,4,0,kw_84},
		{"expansion_order_sequence",13,6,5,1,kw_97,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_expansion_file",11,0,8,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,9,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"least_interpolation",0,6,5,1,kw_100,0.,0.,4,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"normalized",8,0,7,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,5,1,kw_100,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,5,1,kw_100,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_102,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"quadrature_order_sequence",13,3,5,1,kw_103,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"sparse_grid_level_sequence",13,5,5,1,kw_104,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_106[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_107[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_108[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_109[3] = {
		{"dimension_adaptive",8,2,1,1,kw_108},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_110[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_111[2] = {
		{"dimension_adaptive",8,2,1,1,kw_110},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_112[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_113[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_114[13] = {
		{"allocation_control",8,1,3,0,kw_106},
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,8,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,4,0,kw_107},
		{"full_covariance",8,0,8,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"h_refinement",8,3,1,0,kw_109,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"p_refinement",8,2,1,0,kw_111,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,6,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"quadrature_order_sequence",13,3,5,1,kw_112,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"sparse_grid_level_sequence",13,7,5,1,kw_113,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"use_derivatives",8,0,7,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_115[1] = {
		{"estimator_rate",10,0,1,0,0,0.,0.,0,N_mdm(Real,multilevEstimatorRate)}
		},
	kw_116[2] = {
		{"estimator_variance",8,1,1,1,kw_115,0.,0.,0,N_mdm(type,multilevAllocControl_ESTIMATOR_VARIANCE)},
		{"rip_sampling",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_RIP_SAMPLING)}
		},
	kw_117[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_118[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_119[3] = {
		{"adapted",8,2,1,1,kw_118,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_120[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_121[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_122[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_123[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_124[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_125[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_126[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_120,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_120,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_121,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_122,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_123,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_123,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_122,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_124,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_125,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_125,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_127[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_128[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_129[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_128,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_130[6] = {
		{"basis_type",8,3,2,0,kw_119},
		{"collocation_ratio",10,21,3,1,kw_126,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_127,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_129,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_129,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_131[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_132[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_131,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_133[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_132,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_132,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_134[12] = {
		{"allocation_control",8,2,1,0,kw_116},
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,2,0,kw_117},
		{"expansion_order_sequence",13,6,3,1,kw_130,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_expansion_file",11,0,6,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"least_interpolation",0,6,3,1,kw_133,0.,0.,3,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"normalized",8,0,5,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,3,1,kw_133,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,3,1,kw_133,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_135[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_136[3] = {
		{"adapted",8,2,1,1,kw_135,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_137[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_138[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_139[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_140[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_141[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_142[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_143[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_137,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_137,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_138,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_139,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_140,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_140,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_139,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_141,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_142,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_142,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_144[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_145[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_146[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_147[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_148[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_149[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_150[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_144,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_144,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_145,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_146,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_147,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_147,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_146,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_148,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_149,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_149,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_151[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_152[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_153[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_152,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_154[8] = {
		{"basis_type",8,3,2,0,kw_136},
		{"collocation_points",9,19,3,1,kw_143,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"collocation_ratio",10,19,3,1,kw_150,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples",9,2,3,1,kw_151,0.,0.,0,N_mdm(sizet,expansionSamples)},
		{"import_build_points_file",11,4,4,0,kw_153,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_153,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,5,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)}
		},
	kw_155[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_156[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_155,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_157[7] = {
		{"collocation_points",9,0,1,1,0,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"import_build_points_file",11,4,4,0,kw_156,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_156,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,5,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_158[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_159[2] = {
		{"dimension_adaptive",8,3,1,1,kw_158},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_160[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_161[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_162[16] = {
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"cubature_integrand",9,0,3,1,0,0.,0.,0,N_mdm(ushint,cubIntOrder)},
		{"diagonal_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"expansion_order",9,8,3,1,kw_154,0.,0.,0,N_mdm(ushint,expansionOrder)},
		{"export_expansion_file",11,0,6,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"import_expansion_file",11,0,3,1,0,0.,0.,0,N_mdm(str,importExpansionFile)},
		{"least_interpolation",0,7,3,1,kw_157,0.,0.,4,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"normalized",8,0,5,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,7,3,1,kw_157,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,7,3,1,kw_157,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_159,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"quadrature_order",9,3,3,1,kw_160,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"sparse_grid_level",9,5,3,1,kw_161,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_163[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_164[3] = {
		{"dimension_adaptive",8,2,1,1,kw_163},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_165[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_166[2] = {
		{"dimension_adaptive",8,2,1,1,kw_165},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_167[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_168[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_169[11] = {
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,6,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"full_covariance",8,0,6,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"h_refinement",8,3,1,0,kw_164,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"p_refinement",8,2,1,0,kw_166,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,4,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"quadrature_order",9,3,3,1,kw_167,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"sparse_grid_level",9,7,3,1,kw_168,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_170[7] = {
		{"gaussian_process",8,6,1,1,kw_82},
		{"kriging",0,6,1,1,kw_82,0.,0.,-1},
		{"mf_pce",8,16,1,1,kw_105,0.,0.,0,N_mdm(type,emulatorType_MF_PCE_EMULATOR)},
		{"mf_sc",8,13,1,1,kw_114,0.,0.,0,N_mdm(type,emulatorType_MF_SC_EMULATOR)},
		{"ml_pce",8,12,1,1,kw_134,0.,0.,0,N_mdm(type,emulatorType_ML_PCE_EMULATOR)},
		{"pce",8,16,1,1,kw_162,0.,0.,0,N_mdm(type,emulatorType_PCE_EMULATOR)},
		{"sc",8,11,1,1,kw_169,0.,0.,0,N_mdm(type,emulatorType_SC_EMULATOR)}
		},
	kw_171[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_172[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_171,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_173[11] = {
		{"chain_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,chainSamples)},
		{"chains",0x29,0,3,0,0,3.,0.,0,N_mdm(int,numChains)},
		{"crossover_chain_pairs",0x29,0,5,0,0,0.,0.,0,N_mdm(int,crossoverChainPairs)},
		{"emulator",8,7,8,0,kw_170},
		{"export_chain_points_file",11,3,10,0,kw_172,0.,0.,0,N_mdm(str,exportMCMCPtsFile)},
		{"gr_threshold",0x1a,0,6,0,0,0.,0.,0,N_mdm(Real,grThreshold)},
		{"jump_step",0x29,0,7,0,0,0.,0.,0,N_mdm(int,jumpStep)},
		{"num_cr",0x29,0,4,0,0,1.,0.,0,N_mdm(int,numCR)},
		{"samples",1,0,1,1,0,0.,0.,-8,N_mdm(int,chainSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"standardized_space",8,0,9,0,0,0.,0.,0,N_mdm(true,standardizedSpace)}
		},
	kw_174[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importCandFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importCandFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importCandFormat_TABULAR_IFACE_ID)}
		},
	kw_175[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importCandFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_174,0.,0.,0,N_mdm(utype,importCandFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importCandFormat_TABULAR_NONE)}
		},
	kw_176[7] = {
		{"batch_size",0x29,0,4,0,0,1.,0.,0,N_mdm(int,batchSize)},
		{"import_candidate_points_file",11,3,5,0,kw_175,0.,0.,0,N_mdm(str,importCandPtsFile)},
		{"initial_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,numSamples)},
		{"ksg2",8,0,6,0,0,0.,0.,0,N_mdm(true,mutualInfoKSG2)},
		{"max_hifi_evaluations",0x29,0,3,0,0,0.,0.,0,N_mdm(int,maxHifiEvals)},
		{"num_candidates",0x19,0,2,2,0,0.,0.,0,N_mdm(sizet,numCandidates)},
		{"samples",1,0,1,1,0,0.,0.,-4,N_mdm(int,numSamples)}
		},
	kw_177[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_178[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_177,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_179[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_180[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_179,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_181[1] = {
		{"update_period",9,0,1,0,0,0.,0.,0,N_mdm(int,proposalCovUpdatePeriod)}
		},
	kw_182[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_matrix)}
		},
	kw_183[1] = {
		{"multiplier",0x1a,0,1,0,0,0.,0.,0,N_mdm(Real,priorPropCovMult)}
		},
	kw_184[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_matrix)}
		},
	kw_185[4] = {
		{"derivatives",8,1,1,1,kw_181,0.,0.,0,N_mdm(lit,proposalCovType_derivatives)},
		{"filename",11,2,1,1,kw_182,0.,0.,0,N_mdm(str,proposalCovFile)},
		{"prior",8,1,1,1,kw_183,0.,0.,0,N_mdm(lit,proposalCovType_prior)},
		{"values",14,2,1,1,kw_184,0.,0.,0,N_mdm(RealDL,proposalCovData)}
		},
	kw_186[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_187[17] = {
		{"adaptive_metropolis",8,0,10,0,0,0.,0.,0,N_mdm(lit,mcmcType_adaptive_metropolis)},
		{"build_samples",9,0,4,2,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"chain_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,chainSamples)},
		{"delayed_rejection",8,0,10,0,0,0.,0.,0,N_mdm(lit,mcmcType_delayed_rejection)},
		{"dram",8,0,10,0,0,0.,0.,0,N_mdm(lit,mcmcType_dram)},
		{"export_chain_points_file",11,3,9,0,kw_178,0.,0.,0,N_mdm(str,exportMCMCPtsFile)},
		{"gpmsa_normalize",8,0,8,0,0,0.,0.,0,N_mdm(true,gpmsaNormalize)},
		{"import_build_points_file",11,3,5,0,kw_180,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,3,5,0,kw_180,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"logit_transform",8,0,7,0,0,0.,0.,0,N_mdm(true,logitTransform)},
		{"metropolis_hastings",8,0,10,0,0,0.,0.,0,N_mdm(lit,mcmcType_metropolis_hastings)},
		{"options_file",11,0,12,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)},
		{"proposal_covariance",8,4,11,0,kw_185,0.,0.,0,N_mdm(lit,proposalCovType_user)},
		{"rng",8,2,3,0,kw_186},
		{"samples",1,0,1,1,0,0.,0.,-12,N_mdm(int,chainSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"standardized_space",8,0,6,0,0,0.,0.,0,N_mdm(true,standardizedSpace)}
		},
	kw_188[1] = {
		{"trend_order",0x29,0,1,0,0,0.,0.,0,N_mdm(shint,polynomialOrder)}
		},
	kw_189[1] = {
		{"basis_order",0x29,0,1,0,0,0.,0.,0,N_mdm(shint,polynomialOrder)}
		},
	kw_190[3] = {
		{"gaussian_process",8,1,1,1,kw_188,0.,0.,0,N_mdm(lit,modelDiscrepancyType_global_kriging)},
		{"kriging",0,1,1,1,kw_188,0.,0.,-1,N_mdm(lit,modelDiscrepancyType_global_kriging)},
		{"polynomial",8,1,1,1,kw_189,0.,0.,0,N_mdm(lit,modelDiscrepancyType_global_polynomial)}
		},
	kw_191[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportCorrModelFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportCorrModelFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportCorrModelFormat_TABULAR_IFACE_ID)}
		},
	kw_192[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportCorrModelFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_191,0.,0.,0,N_mdm(utype,exportCorrModelFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportCorrModelFormat_TABULAR_NONE)}
		},
	kw_193[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportCorrVarFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportCorrVarFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportCorrVarFormat_TABULAR_IFACE_ID)}
		},
	kw_194[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportCorrVarFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_193,0.,0.,0,N_mdm(utype,exportCorrVarFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportCorrVarFormat_TABULAR_NONE)}
		},
	kw_195[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportDiscrepFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportDiscrepFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportDiscrepFormat_TABULAR_IFACE_ID)}
		},
	kw_196[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportDiscrepFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_195,0.,0.,0,N_mdm(utype,exportDiscrepFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportDiscrepFormat_TABULAR_NONE)}
		},
	kw_197[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importPredConfigFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importPredConfigFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importPredConfigFormat_TABULAR_IFACE_ID)}
		},
	kw_198[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importPredConfigFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_197,0.,0.,0,N_mdm(utype,importPredConfigFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importPredConfigFormat_TABULAR_NONE)}
		},
	kw_199[7] = {
		{"discrepancy_type",8,3,1,0,kw_190},
		{"export_corrected_model_file",11,3,6,0,kw_192,0.,0.,0,N_mdm(str,exportCorrModelFile)},
		{"export_corrected_variance_file",11,3,7,0,kw_194,0.,0.,0,N_mdm(str,exportCorrVarFile)},
		{"export_discrepancy_file",11,3,5,0,kw_196,0.,0.,0,N_mdm(str,exportDiscrepFile)},
		{"import_prediction_configs",11,3,4,0,kw_198,0.,0.,0,N_mdm(str,importPredConfigs)},
		{"num_prediction_configs",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,numPredConfigs)},
		{"prediction_configs",14,0,3,0,0,0.,0.,0,N_mdm(RealDL,predictionConfigList)}
		},
	kw_200[3] = {
		{"evidence_samples",9,0,2,0,0,0.,0.,0,N_mdm(int,evidenceSamples)},
		{"laplace_approx",8,0,3,0,0,0.,0.,0,N_mdm(true,modelEvidLaplace)},
		{"mc_approx",8,0,1,0,0,0.,0.,0,N_mdm(true,modelEvidMC)}
		},
	kw_201[3] = {
		{"adapt_scale",10,0,3,0,0,0.,0.,0,N_mdm(Real,amScale)},
		{"period_num_steps",9,0,1,0,0,0.,0.,0,N_mdm(int,amPeriodNumSteps)},
		{"starting_step",9,0,2,0,0,0.,0.,0,N_mdm(int,amStartingStep)}
		},
	kw_202[3] = {
		{"delay_scale",10,0,3,0,0,0.,0.,0,N_mdm(Real,drScale)},
		{"num_stages",9,0,1,0,0,0.,0.,0,N_mdm(int,drNumStages)},
		{"scale_type",11,0,2,0,0,0.,0.,0,N_mdm(str,drScaleType)}
		},
	kw_203[13] = {
		{"adapt_end",9,0,4,0,0,0.,0.,0,N_mdm(int,diliAdaptEnd)},
		{"adapt_interval",9,0,2,0,0,0.,0.,0,N_mdm(int,diliAdaptInterval)},
		{"adapt_start",9,0,3,0,0,0.,0.,0,N_mdm(int,diliAdaptStart)},
		{"hess_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,diliHessTolerance)},
		{"hessian_type",11,0,1,0,0,0.,0.,0,N_mdm(str,diliHessianType)},
		{"initial_weight",9,0,5,0,0,0.,0.,0,N_mdm(int,diliInitialWeight)},
		{"lis_tolerance",10,0,7,0,0,0.,0.,0,N_mdm(Real,diliLISTolerance)},
		{"ses_abs_tol",10,0,10,0,0,0.,0.,0,N_mdm(Real,diliSesAbsTol)},
		{"ses_block_size",9,0,13,0,0,0.,0.,0,N_mdm(int,diliSesBlockSize)},
		{"ses_exp_rank",9,0,11,0,0,0.,0.,0,N_mdm(int,diliSesExpRank)},
		{"ses_num_eigs",9,0,8,0,0,0.,0.,0,N_mdm(int,diliSesNumEigs)},
		{"ses_overs_factor",9,0,12,0,0,0.,0.,0,N_mdm(int,diliSesOversFactor)},
		{"ses_rel_tol",10,0,9,0,0,0.,0.,0,N_mdm(Real,diliSesRelTol)}
		},
	kw_204[6] = {
		{"adapt_scale",10,0,6,0,0,0.,0.,0,N_mdm(Real,amScale)},
		{"delay_scale",10,0,3,0,0,0.,0.,0,N_mdm(Real,drScale)},
		{"num_stages",9,0,1,0,0,0.,0.,0,N_mdm(int,drNumStages)},
		{"period_num_steps",9,0,4,0,0,0.,0.,0,N_mdm(int,amPeriodNumSteps)},
		{"scale_type",11,0,2,0,0,0.,0.,0,N_mdm(str,drScaleType)},
		{"starting_step",9,0,5,0,0,0.,0.,0,N_mdm(int,amStartingStep)}
		},
	kw_205[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_206[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_205,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_207[1] = {
		{"step_size",10,0,1,0,0,0.,0.,0,N_mdm(Real,malaStepSize)}
		},
	kw_208[3] = {
		{"nip",8,0,1,1,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NONE)},
		{"sqp",8,0,1,1,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)}
		},
	kw_209[1] = {
		{"update_period",9,0,1,0,0,0.,0.,0,N_mdm(int,proposalCovUpdatePeriod)}
		},
	kw_210[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_matrix)}
		},
	kw_211[1] = {
		{"multiplier",0x1a,0,1,0,0,0.,0.,0,N_mdm(Real,priorPropCovMult)}
		},
	kw_212[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_matrix)}
		},
	kw_213[4] = {
		{"derivatives",8,1,1,1,kw_209,0.,0.,0,N_mdm(lit,proposalCovType_derivatives)},
		{"filename",11,2,1,1,kw_210,0.,0.,0,N_mdm(str,proposalCovFile)},
		{"prior",8,1,1,1,kw_211,0.,0.,0,N_mdm(lit,proposalCovType_prior)},
		{"values",14,2,1,1,kw_212,0.,0.,0,N_mdm(RealDL,proposalCovData)}
		},
	kw_214[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_215[13] = {
		{"adaptive_metropolis",8,3,5,0,kw_201,0.,0.,0,N_mdm(lit,mcmcType_adaptive_metropolis)},
		{"chain_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,chainSamples)},
		{"delayed_rejection",8,3,5,0,kw_202,0.,0.,0,N_mdm(lit,mcmcType_delayed_rejection)},
		{"dili",8,13,5,0,kw_203,0.,0.,0,N_mdm(lit,mcmcType_dili)},
		{"dram",8,6,5,0,kw_204,0.,0.,0,N_mdm(lit,mcmcType_dram)},
		{"export_chain_points_file",11,3,4,0,kw_206,0.,0.,0,N_mdm(str,exportMCMCPtsFile)},
		{"mala",8,1,5,0,kw_207,0.,0.,0,N_mdm(lit,mcmcType_mala)},
		{"metropolis_hastings",8,0,5,0,0,0.,0.,0,N_mdm(lit,mcmcType_metropolis_hastings)},
		{"pre_solve",8,3,6,0,kw_208},
		{"proposal_covariance",8,4,7,0,kw_213,0.,0.,0,N_mdm(lit,proposalCovType_user)},
		{"rng",8,2,3,0,kw_214},
		{"samples",1,0,1,1,0,0.,0.,-10,N_mdm(int,chainSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_216[1] = {
		{"ksg2",8,0,1,0,0,0.,0.,0,N_mdm(true,mutualInfoKSG2)}
		},
	kw_217[3] = {
		{"kde",8,0,3,0,0,0.,0.,0,N_mdm(true,posteriorStatsKDE)},
		{"kl_divergence",8,0,1,0,0,0.,0.,0,N_mdm(true,posteriorStatsKL)},
		{"mutual_info",8,1,2,0,kw_216,0.,0.,0,N_mdm(true,posteriorStatsMutual)}
		},
	kw_218[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_219[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_220[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_219,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_221[6] = {
		{"build_samples",9,0,2,0,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"import_build_points_file",11,4,4,0,kw_220,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_220,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,3,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)},
		{"surfpack",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_222[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_223[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_224[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_225[3] = {
		{"adapted",8,2,1,1,kw_224,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_226[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_227[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_228[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_229[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_230[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_231[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_232[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_226,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_226,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_227,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_228,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_229,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_229,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_228,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_230,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_231,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_231,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_233[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_234[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_235[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_234,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_236[6] = {
		{"basis_type",8,3,2,0,kw_225},
		{"collocation_ratio",10,21,3,1,kw_232,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_233,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_235,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_235,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_237[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_238[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_237,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_239[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_238,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_238,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_240[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_241[2] = {
		{"dimension_adaptive",8,3,1,1,kw_240},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_242[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_243[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_244[16] = {
		{"allocation_control",8,1,3,0,kw_222},
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,9,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,4,0,kw_223},
		{"expansion_order_sequence",13,6,5,1,kw_236,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_expansion_file",11,0,8,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,9,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"least_interpolation",0,6,5,1,kw_239,0.,0.,4,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"normalized",8,0,7,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,5,1,kw_239,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,5,1,kw_239,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_241,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"quadrature_order_sequence",13,3,5,1,kw_242,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"sparse_grid_level_sequence",13,5,5,1,kw_243,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_245[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_246[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_247[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_248[3] = {
		{"dimension_adaptive",8,2,1,1,kw_247},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_249[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_250[2] = {
		{"dimension_adaptive",8,2,1,1,kw_249},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_251[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_252[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_253[13] = {
		{"allocation_control",8,1,3,0,kw_245},
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,8,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,4,0,kw_246},
		{"full_covariance",8,0,8,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"h_refinement",8,3,1,0,kw_248,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"p_refinement",8,2,1,0,kw_250,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,6,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"quadrature_order_sequence",13,3,5,1,kw_251,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"sparse_grid_level_sequence",13,7,5,1,kw_252,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"use_derivatives",8,0,7,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_254[1] = {
		{"estimator_rate",10,0,1,0,0,0.,0.,0,N_mdm(Real,multilevEstimatorRate)}
		},
	kw_255[2] = {
		{"estimator_variance",8,1,1,1,kw_254,0.,0.,0,N_mdm(type,multilevAllocControl_ESTIMATOR_VARIANCE)},
		{"rip_sampling",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_RIP_SAMPLING)}
		},
	kw_256[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_257[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_258[3] = {
		{"adapted",8,2,1,1,kw_257,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_259[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_260[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_261[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_262[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_263[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_264[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_265[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_259,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_259,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_260,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_261,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_262,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_262,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_261,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_263,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_264,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_264,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_266[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_267[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_268[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_267,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_269[6] = {
		{"basis_type",8,3,2,0,kw_258},
		{"collocation_ratio",10,21,3,1,kw_265,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_266,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_268,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_268,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_270[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_271[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_270,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_272[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_271,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_271,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_273[12] = {
		{"allocation_control",8,2,1,0,kw_255},
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,2,0,kw_256},
		{"expansion_order_sequence",13,6,3,1,kw_269,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_expansion_file",11,0,6,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"least_interpolation",0,6,3,1,kw_272,0.,0.,3,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"normalized",8,0,5,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,3,1,kw_272,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,3,1,kw_272,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_274[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_275[3] = {
		{"adapted",8,2,1,1,kw_274,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_276[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_277[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_278[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_279[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_280[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_281[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_282[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_276,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_276,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_277,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_278,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_279,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_279,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_278,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_280,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_281,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_281,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_283[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_284[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_285[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_286[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_287[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_288[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_289[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_283,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_283,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_284,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_285,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_286,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_286,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_285,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_287,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_288,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_288,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_290[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_291[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_292[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_291,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_293[8] = {
		{"basis_type",8,3,2,0,kw_275},
		{"collocation_points",9,19,3,1,kw_282,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"collocation_ratio",10,19,3,1,kw_289,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples",9,2,3,1,kw_290,0.,0.,0,N_mdm(sizet,expansionSamples)},
		{"import_build_points_file",11,4,4,0,kw_292,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_292,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,5,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)}
		},
	kw_294[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_295[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_294,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_296[7] = {
		{"collocation_points",9,0,1,1,0,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"import_build_points_file",11,4,4,0,kw_295,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_295,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,5,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_297[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_298[2] = {
		{"dimension_adaptive",8,3,1,1,kw_297},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_299[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_300[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_301[16] = {
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"cubature_integrand",9,0,3,1,0,0.,0.,0,N_mdm(ushint,cubIntOrder)},
		{"diagonal_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"expansion_order",9,8,3,1,kw_293,0.,0.,0,N_mdm(ushint,expansionOrder)},
		{"export_expansion_file",11,0,6,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"import_expansion_file",11,0,3,1,0,0.,0.,0,N_mdm(str,importExpansionFile)},
		{"least_interpolation",0,7,3,1,kw_296,0.,0.,4,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"normalized",8,0,5,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,7,3,1,kw_296,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,7,3,1,kw_296,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_298,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"quadrature_order",9,3,3,1,kw_299,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"sparse_grid_level",9,5,3,1,kw_300,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_302[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_303[3] = {
		{"dimension_adaptive",8,2,1,1,kw_302},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_304[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_305[2] = {
		{"dimension_adaptive",8,2,1,1,kw_304},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_306[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_307[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_308[11] = {
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,6,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"full_covariance",8,0,6,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"h_refinement",8,3,1,0,kw_303,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"p_refinement",8,2,1,0,kw_305,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,4,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"quadrature_order",9,3,3,1,kw_306,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"sparse_grid_level",9,7,3,1,kw_307,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_309[7] = {
		{"gaussian_process",8,6,1,1,kw_221},
		{"kriging",0,6,1,1,kw_221,0.,0.,-1},
		{"mf_pce",8,16,1,1,kw_244,0.,0.,0,N_mdm(type,emulatorType_MF_PCE_EMULATOR)},
		{"mf_sc",8,13,1,1,kw_253,0.,0.,0,N_mdm(type,emulatorType_MF_SC_EMULATOR)},
		{"ml_pce",8,12,1,1,kw_273,0.,0.,0,N_mdm(type,emulatorType_ML_PCE_EMULATOR)},
		{"pce",8,16,1,1,kw_301,0.,0.,0,N_mdm(type,emulatorType_PCE_EMULATOR)},
		{"sc",8,11,1,1,kw_308,0.,0.,0,N_mdm(type,emulatorType_SC_EMULATOR)}
		},
	kw_310[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_311[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_310,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_312[3] = {
		{"nip",8,0,1,1,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NONE)},
		{"sqp",8,0,1,1,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)}
		},
	kw_313[1] = {
		{"update_period",9,0,1,0,0,0.,0.,0,N_mdm(int,proposalCovUpdatePeriod)}
		},
	kw_314[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_matrix)}
		},
	kw_315[1] = {
		{"multiplier",0x1a,0,1,0,0,0.,0.,0,N_mdm(Real,priorPropCovMult)}
		},
	kw_316[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,proposalCovInputType_matrix)}
		},
	kw_317[4] = {
		{"derivatives",8,1,1,1,kw_313,0.,0.,0,N_mdm(lit,proposalCovType_derivatives)},
		{"filename",11,2,1,1,kw_314,0.,0.,0,N_mdm(str,proposalCovFile)},
		{"prior",8,1,1,1,kw_315,0.,0.,0,N_mdm(lit,proposalCovType_prior)},
		{"values",14,2,1,1,kw_316,0.,0.,0,N_mdm(RealDL,proposalCovData)}
		},
	kw_318[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_319[16] = {
		{"adaptive_metropolis",8,0,8,0,0,0.,0.,0,N_mdm(lit,mcmcType_adaptive_metropolis)},
		{"chain_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,chainSamples)},
		{"delayed_rejection",8,0,8,0,0,0.,0.,0,N_mdm(lit,mcmcType_delayed_rejection)},
		{"dram",8,0,8,0,0,0.,0.,0,N_mdm(lit,mcmcType_dram)},
		{"emulator",8,7,4,0,kw_309},
		{"export_chain_points_file",11,3,7,0,kw_311,0.,0.,0,N_mdm(str,exportMCMCPtsFile)},
		{"logit_transform",8,0,6,0,0,0.,0.,0,N_mdm(true,logitTransform)},
		{"metropolis_hastings",8,0,8,0,0,0.,0.,0,N_mdm(lit,mcmcType_metropolis_hastings)},
		{"multilevel",8,0,8,0,0,0.,0.,0,N_mdm(lit,mcmcType_multilevel)},
		{"options_file",11,0,11,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)},
		{"pre_solve",8,3,9,0,kw_312},
		{"proposal_covariance",8,4,10,0,kw_317,0.,0.,0,N_mdm(lit,proposalCovType_user)},
		{"rng",8,2,3,0,kw_318},
		{"samples",1,0,1,1,0,0.,0.,-12,N_mdm(int,chainSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"standardized_space",8,0,5,0,0,0.,0.,0,N_mdm(true,standardizedSpace)}
		},
	kw_320[2] = {
		{"diagonal",8,0,1,1,0,0.,0.,0,N_mdm(lit,dataDistCovInputType_diagonal)},
		{"matrix",8,0,1,1,0,0.,0.,0,N_mdm(lit,dataDistCovInputType_matrix)}
		},
	kw_321[2] = {
		{"covariance",14,2,2,2,kw_320,0.,0.,0,N_mdm(RealDL,dataDistCovariance)},
		{"means",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,dataDistMeans)}
		},
	kw_322[2] = {
		{"gaussian",8,2,1,1,kw_321},
		{"obs_data_filename",11,0,1,1,0,0.,0.,0,N_mdm(str,dataDistFile)}
		},
	kw_323[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_324[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_323,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_325[6] = {
		{"build_samples",9,0,2,0,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"import_build_points_file",11,4,4,0,kw_324,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_324,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,3,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)},
		{"surfpack",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_326[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_327[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_328[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_329[3] = {
		{"adapted",8,2,1,1,kw_328,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_330[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_331[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_332[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_333[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_334[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_335[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_336[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_330,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_330,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_331,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_332,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_333,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_333,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_332,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_334,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_335,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_335,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_337[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_338[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_339[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_338,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_340[6] = {
		{"basis_type",8,3,2,0,kw_329},
		{"collocation_ratio",10,21,3,1,kw_336,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_337,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_339,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_339,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_341[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_342[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_341,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_343[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_342,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_342,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_344[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_345[2] = {
		{"dimension_adaptive",8,3,1,1,kw_344},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_346[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_347[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_348[16] = {
		{"allocation_control",8,1,3,0,kw_326},
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,9,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,4,0,kw_327},
		{"expansion_order_sequence",13,6,5,1,kw_340,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_expansion_file",11,0,8,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,9,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"least_interpolation",0,6,5,1,kw_343,0.,0.,4,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"normalized",8,0,7,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,5,1,kw_343,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,5,1,kw_343,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_345,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"quadrature_order_sequence",13,3,5,1,kw_346,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"sparse_grid_level_sequence",13,5,5,1,kw_347,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_349[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_350[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_351[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_352[3] = {
		{"dimension_adaptive",8,2,1,1,kw_351},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_353[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_354[2] = {
		{"dimension_adaptive",8,2,1,1,kw_353},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_355[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_356[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_357[13] = {
		{"allocation_control",8,1,3,0,kw_349},
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,8,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,4,0,kw_350},
		{"full_covariance",8,0,8,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"h_refinement",8,3,1,0,kw_352,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"p_refinement",8,2,1,0,kw_354,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,6,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"quadrature_order_sequence",13,3,5,1,kw_355,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"sparse_grid_level_sequence",13,7,5,1,kw_356,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"use_derivatives",8,0,7,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_358[1] = {
		{"estimator_rate",10,0,1,0,0,0.,0.,0,N_mdm(Real,multilevEstimatorRate)}
		},
	kw_359[2] = {
		{"estimator_variance",8,1,1,1,kw_358,0.,0.,0,N_mdm(type,multilevAllocControl_ESTIMATOR_VARIANCE)},
		{"rip_sampling",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_RIP_SAMPLING)}
		},
	kw_360[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_361[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_362[3] = {
		{"adapted",8,2,1,1,kw_361,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_363[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_364[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_365[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_366[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_367[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_368[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_369[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_363,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_363,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_364,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_365,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_366,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_366,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_365,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_367,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_368,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_368,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_370[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_371[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_372[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_371,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_373[6] = {
		{"basis_type",8,3,2,0,kw_362},
		{"collocation_ratio",10,21,3,1,kw_369,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_370,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_372,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_372,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_374[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_375[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_374,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_376[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_375,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_375,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_377[12] = {
		{"allocation_control",8,2,1,0,kw_359},
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,2,0,kw_360},
		{"expansion_order_sequence",13,6,3,1,kw_373,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_expansion_file",11,0,6,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"least_interpolation",0,6,3,1,kw_376,0.,0.,3,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"normalized",8,0,5,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,3,1,kw_376,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,3,1,kw_376,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_378[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_379[3] = {
		{"adapted",8,2,1,1,kw_378,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_380[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_381[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_382[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_383[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_384[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_385[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_386[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_380,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_380,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_381,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_382,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_383,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_383,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_382,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_384,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_385,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_385,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_387[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_388[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_389[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_390[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_391[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_392[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_393[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_387,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_387,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_388,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_389,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_390,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_390,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_389,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_391,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_392,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_392,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_394[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_395[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_396[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_395,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_397[8] = {
		{"basis_type",8,3,2,0,kw_379},
		{"collocation_points",9,19,3,1,kw_386,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"collocation_ratio",10,19,3,1,kw_393,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples",9,2,3,1,kw_394,0.,0.,0,N_mdm(sizet,expansionSamples)},
		{"import_build_points_file",11,4,4,0,kw_396,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_396,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,5,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)}
		},
	kw_398[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_399[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_398,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_400[7] = {
		{"collocation_points",9,0,1,1,0,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"import_build_points_file",11,4,4,0,kw_399,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_399,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"posterior_adaptive",8,0,5,0,0,0.,0.,0,N_mdm(true,adaptPosteriorRefine)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_401[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_402[2] = {
		{"dimension_adaptive",8,3,1,1,kw_401},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_403[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_404[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_405[16] = {
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"cubature_integrand",9,0,3,1,0,0.,0.,0,N_mdm(ushint,cubIntOrder)},
		{"diagonal_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"expansion_order",9,8,3,1,kw_397,0.,0.,0,N_mdm(ushint,expansionOrder)},
		{"export_expansion_file",11,0,6,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"full_covariance",8,0,7,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"import_expansion_file",11,0,3,1,0,0.,0.,0,N_mdm(str,importExpansionFile)},
		{"least_interpolation",0,7,3,1,kw_400,0.,0.,4,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"normalized",8,0,5,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,7,3,1,kw_400,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,7,3,1,kw_400,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_402,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"quadrature_order",9,3,3,1,kw_403,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"sparse_grid_level",9,5,3,1,kw_404,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_406[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_407[3] = {
		{"dimension_adaptive",8,2,1,1,kw_406},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_408[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_409[2] = {
		{"dimension_adaptive",8,2,1,1,kw_408},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_410[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_411[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_412[11] = {
		{"askey",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"diagonal_covariance",8,0,6,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"full_covariance",8,0,6,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"h_refinement",8,3,1,0,kw_407,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"p_refinement",8,2,1,0,kw_409,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,4,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"quadrature_order",9,3,3,1,kw_410,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"sparse_grid_level",9,7,3,1,kw_411,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"wiener",8,0,4,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_413[7] = {
		{"gaussian_process",8,6,1,1,kw_325},
		{"kriging",0,6,1,1,kw_325,0.,0.,-1},
		{"mf_pce",8,16,1,1,kw_348,0.,0.,0,N_mdm(type,emulatorType_MF_PCE_EMULATOR)},
		{"mf_sc",8,13,1,1,kw_357,0.,0.,0,N_mdm(type,emulatorType_MF_SC_EMULATOR)},
		{"ml_pce",8,12,1,1,kw_377,0.,0.,0,N_mdm(type,emulatorType_ML_PCE_EMULATOR)},
		{"pce",8,16,1,1,kw_405,0.,0.,0,N_mdm(type,emulatorType_PCE_EMULATOR)},
		{"sc",8,11,1,1,kw_412,0.,0.,0,N_mdm(type,emulatorType_SC_EMULATOR)}
		},
	kw_414[1] = {
		{"posterior_density_export_filename",11,0,1,0,0,0.,0.,0,N_mdm(str,posteriorDensityExportFilename)}
		},
	kw_415[1] = {
		{"posterior_samples_export_filename",11,0,1,0,0,0.,0.,0,N_mdm(str,posteriorSamplesExportFilename)}
		},
	kw_416[8] = {
		{"data_distribution",8,2,5,2,kw_322},
		{"emulator",8,7,3,0,kw_413},
		{"evaluate_posterior_density",8,1,8,0,kw_414,0.,0.,0,N_mdm(true,evaluatePosteriorDensity)},
		{"generate_posterior_samples",8,1,7,0,kw_415,0.,0.,0,N_mdm(true,generatePosteriorSamples)},
		{"posterior_samples_import_filename",11,0,6,0,0,0.,0.,0,N_mdm(str,posteriorSamplesImportFilename)},
		{"pushforward_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,numPushforwardSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"standardized_space",8,0,4,0,0,0.,0.,0,N_mdm(true,standardizedSpace)}
		},
	kw_417[18] = {
		{"burn_in_samples",9,0,4,0,0,0.,0.,0,N_mdm(int,burnInSamples)},
		{"calibrate_error_multipliers",8,5,3,0,kw_78},
		{"chain_diagnostics",8,1,6,0,kw_79,0.,0.,0,N_mdm(true,chainDiagnostics)},
		{"convergence_tolerance",10,0,11,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"dream",8,11,1,1,kw_173,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_DREAM)},
		{"experimental_design",8,7,2,0,kw_176,0.,0.,0,N_mdm(true,adaptExpDesign)},
		{"gpmsa",8,17,1,1,kw_187,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_GPMSA)},
		{"max_iterations",0x29,0,12,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_discrepancy",8,7,8,0,kw_199,0.,0.,0,N_mdm(true,calModelDiscrepancy)},
		{"model_evidence",8,3,7,0,kw_200,0.,0.,0,N_mdm(true,modelEvidence)},
		{"model_pointer",11,0,13,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"muq",8,13,1,1,kw_215,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_MUQ)},
		{"posterior_stats",8,3,5,0,kw_217},
		{"probability_levels",14,1,10,0,kw_218,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"queso",8,16,1,1,kw_319,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_QUESO)},
		{"scaling",8,0,14,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"sub_sampling_period",9,0,9,0,0,0.,0.,0,N_mdm(int,subSamplingPeriod)},
		{"wasabi",8,8,1,1,kw_416,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_WASABI)}
		},
	kw_418[1] = {
		{"model_pointer",11,0,1,0,0,0.,0.,0,N_mdm(str,modelPointer)}
		},
	kw_419[3] = {
		{"method_name",11,1,1,1,kw_418,0.,0.,0,N_mdm(str,subMethodName)},
		{"method_pointer",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodPointer)},
		{"scaling",8,0,2,0,0,0.,0.,0,N_mdm(true,methodScaling)}
		},
	kw_420[4] = {
		{"deltas_per_variable",5,0,2,2,0,0.,0.,3,N_mdm(ivec,stepsPerVariable)},
		{"model_pointer",11,0,3,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"step_vector",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,stepVector)},
		{"steps_per_variable",13,0,2,2,0,0.,0.,0,N_mdm(ivec,stepsPerVariable)}
		},
	kw_421[11] = {
		{"beta_solver_name",11,0,1,1,0,0.,0.,0,N_mdm(str,betaSolverName)},
		{"convergence_tolerance",10,0,7,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,6,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,5,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,9,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,3,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"show_misc_options",8,0,4,0,0,0.,0.,0,N_mdm(true,showMiscOptions)},
		{"solution_accuracy",2,0,2,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,2,0,0,0.,0.,0,N_mdm(Real,solnTarget)}
		},
	kw_422[12] = {
		{"convergence_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"initial_delta",10,0,1,0,0,0.,0.,0,N_mdm(Real,initDelta)},
		{"max_function_evaluations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,6,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,11,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,10,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,4,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"show_misc_options",8,0,5,0,0,0.,0.,0,N_mdm(true,showMiscOptions)},
		{"solution_accuracy",2,0,3,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,3,0,0,0.,0.,0,N_mdm(Real,solnTarget)},
		{"variable_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,threshDelta)}
		},
	kw_423[2] = {
		{"all_dimensions",8,0,1,1,0,0.,0.,0,N_mdm(lit,boxDivision_all_dimensions)},
		{"major_dimension",8,0,1,1,0,0.,0.,0,N_mdm(lit,boxDivision_major_dimension)}
		},
	kw_424[16] = {
		{"constraint_penalty",10,0,6,0,0,0.,0.,0,N_mdm(Real,constraintPenalty)},
		{"convergence_tolerance",10,0,12,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"division",8,2,1,0,kw_423},
		{"global_balance_parameter",10,0,2,0,0,0.,0.,0,N_mdm(Real,globalBalanceParam)},
		{"local_balance_parameter",10,0,3,0,0,0.,0.,0,N_mdm(Real,localBalanceParam)},
		{"max_boxsize_limit",10,0,4,0,0,0.,0.,0,N_mdm(Real,maxBoxSize)},
		{"max_function_evaluations",0x29,0,13,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,11,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"min_boxsize_limit",10,0,5,0,0,0.,0.,0,N_mdm(Real,minBoxSize)},
		{"misc_options",15,0,10,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,15,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,14,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,8,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"show_misc_options",8,0,9,0,0,0.,0.,0,N_mdm(true,showMiscOptions)},
		{"solution_accuracy",2,0,7,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,7,0,0,0.,0.,0,N_mdm(Real,solnTarget)}
		},
	kw_425[3] = {
		{"blend",8,0,1,1,0,0.,0.,0,N_mdm(lit,crossoverType_blend)},
		{"two_point",8,0,1,1,0,0.,0.,0,N_mdm(lit,crossoverType_two_point)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(lit,crossoverType_uniform)}
		},
	kw_426[2] = {
		{"linear_rank",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessType_linear_rank)},
		{"merit_function",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessType_proportional)}
		},
	kw_427[3] = {
		{"flat_file",11,0,1,1,0,0.,0.,0,N_mdm(slit2,TYPE_DATA_initializationType_flat_file)},
		{"simple_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,initializationType_random)},
		{"unique_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,initializationType_unique_random)}
		},
	kw_428[2] = {
		{"mutation_range",9,0,2,0,0,0.,0.,0,N_mdm(int,mutationRange)},
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real,mutationScale)}
		},
	kw_429[2] = {
		{"mutation_range",9,0,2,0,0,0.,0.,0,N_mdm(int,mutationRange)},
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real,mutationScale)}
		},
	kw_430[2] = {
		{"mutation_range",9,0,2,0,0,0.,0.,0,N_mdm(int,mutationRange)},
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real,mutationScale)}
		},
	kw_431[5] = {
		{"non_adaptive",8,0,2,0,0,0.,0.,0,N_mdm(false,mutationAdaptive)},
		{"offset_cauchy",8,2,1,1,kw_428,0.,0.,0,N_mdm(lit,mutationType_offset_cauchy)},
		{"offset_normal",8,2,1,1,kw_429,0.,0.,0,N_mdm(lit,mutationType_offset_normal)},
		{"offset_uniform",8,2,1,1,kw_430,0.,0.,0,N_mdm(lit,mutationType_offset_uniform)},
		{"replace_uniform",8,0,1,1,0,0.,0.,0,N_mdm(lit,mutationType_replace_uniform)}
		},
	kw_432[4] = {
		{"chc",9,0,1,1,0,0.,0.,0,N_mdm(ilit2,TYPE_DATA_replacementType_chc)},
		{"elitist",9,0,1,1,0,0.,0.,0,N_mdm(ilit2,TYPE_DATA_replacementType_elitist)},
		{"new_solutions_generated",9,0,2,0,0,0.,0.,0,N_mdm(int,newSolnsGenerated)},
		{"random",9,0,1,1,0,0.,0.,0,N_mdm(ilit2,TYPE_DATA_replacementType_random)}
		},
	kw_433[19] = {
		{"constraint_penalty",10,0,9,0,0,0.,0.,0,N_mdm(Real,constraintPenalty)},
		{"convergence_tolerance",10,0,15,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"crossover_rate",10,0,5,0,0,0.,0.,0,N_mdm(Real,crossoverRate)},
		{"crossover_type",8,3,6,0,kw_425},
		{"fitness_type",8,2,3,0,kw_426},
		{"initialization_type",8,3,2,0,kw_427},
		{"max_function_evaluations",0x29,0,16,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,14,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,13,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,18,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"mutation_rate",10,0,7,0,0,0.,0.,0,N_mdm(Real,mutationRate)},
		{"mutation_type",8,5,8,0,kw_431},
		{"population_size",0x19,0,1,0,0,0.,0.,0,N_mdm(int,populationSize)},
		{"replacement_type",8,4,4,0,kw_432},
		{"scaling",8,0,17,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,11,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"show_misc_options",8,0,12,0,0,0.,0.,0,N_mdm(true,showMiscOptions)},
		{"solution_accuracy",2,0,10,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,10,0,0,0.,0.,0,N_mdm(Real,solnTarget)}
		},
	kw_434[3] = {
		{"adaptive_pattern",8,0,1,1,0,0.,0.,0,N_mdm(lit,exploratoryMoves_adaptive)},
		{"basic_pattern",8,0,1,1,0,0.,0.,0,N_mdm(lit,exploratoryMoves_simple)},
		{"multi_step",8,0,1,1,0,0.,0.,0,N_mdm(lit,exploratoryMoves_multi_step)}
		},
	kw_435[2] = {
		{"coordinate",8,0,1,1,0,0.,0.,0,N_mdm(lit,patternBasis_coordinate)},
		{"simplex",8,0,1,1,0,0.,0.,0,N_mdm(lit,patternBasis_simplex)}
		},
	kw_436[2] = {
		{"blocking",8,0,1,1,0,0.,0.,0,N_mdm(type,evalSynchronize_BLOCKING_SYNCHRONIZATION)},
		{"nonblocking",8,0,1,1,0,0.,0.,0,N_mdm(type,evalSynchronize_NONBLOCKING_SYNCHRONIZATION)}
		},
	kw_437[22] = {
		{"constant_penalty",8,0,1,0,0,0.,0.,0,N_mdm(true,constantPenalty)},
		{"constraint_penalty",10,0,10,0,0,0.,0.,0,N_mdm(Real,constraintPenalty)},
		{"contraction_factor",10,0,9,0,0,0.,0.,0,N_mdm(Real,contractFactor)},
		{"convergence_tolerance",10,0,18,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"expand_after_success",9,0,3,0,0,0.,0.,0,N_mdm(int,expandAfterSuccess)},
		{"exploratory_moves",8,3,7,0,kw_434},
		{"initial_delta",10,0,11,0,0,0.,0.,0,N_mdm(Real,initDelta)},
		{"max_function_evaluations",0x29,0,19,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,17,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,16,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,21,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"no_expansion",8,0,2,0,0,0.,0.,0,N_mdm(false,expansionFlag)},
		{"pattern_basis",8,2,4,0,kw_435},
		{"scaling",8,0,20,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,14,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"show_misc_options",8,0,15,0,0,0.,0.,0,N_mdm(true,showMiscOptions)},
		{"solution_accuracy",2,0,13,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,13,0,0,0.,0.,0,N_mdm(Real,solnTarget)},
		{"stochastic",8,0,5,0,0,0.,0.,0,N_mdm(true,randomizeOrderFlag)},
		{"synchronization",8,2,8,0,kw_436},
		{"total_pattern_size",9,0,6,0,0,0.,0.,0,N_mdm(int,totalPatternSize)},
		{"variable_tolerance",10,0,12,0,0,0.,0.,0,N_mdm(Real,threshDelta)}
		},
	kw_438[18] = {
		{"constant_penalty",8,0,4,0,0,0.,0.,0,N_mdm(true,constantPenalty)},
		{"constraint_penalty",10,0,6,0,0,0.,0.,0,N_mdm(Real,constraintPenalty)},
		{"contract_after_failure",9,0,1,0,0,0.,0.,0,N_mdm(int,contractAfterFail)},
		{"contraction_factor",10,0,5,0,0,0.,0.,0,N_mdm(Real,contractFactor)},
		{"convergence_tolerance",10,0,14,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"expand_after_success",9,0,3,0,0,0.,0.,0,N_mdm(int,expandAfterSuccess)},
		{"initial_delta",10,0,7,0,0,0.,0.,0,N_mdm(Real,initDelta)},
		{"max_function_evaluations",0x29,0,15,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,13,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,12,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,17,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"no_expansion",8,0,2,0,0,0.,0.,0,N_mdm(false,expansionFlag)},
		{"scaling",8,0,16,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,10,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"show_misc_options",8,0,11,0,0,0.,0.,0,N_mdm(true,showMiscOptions)},
		{"solution_accuracy",2,0,9,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,9,0,0,0.,0.,0,N_mdm(Real,solnTarget)},
		{"variable_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,threshDelta)}
		},
	kw_439[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_440[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_441[1] = {
		{"num_bins",9,0,1,0,0,0.,0.,0,N_mdm(int,vbdViaSamplingNumBins)}
		},
	kw_442[2] = {
		{"binned",8,1,1,1,kw_441,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_BINNED)},
		{"pick_and_freeze",8,0,1,1,0,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_PICK_AND_FREEZE)}
		},
	kw_443[2] = {
		{"drop_tolerance",10,0,1,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"vbd_sampling_method",8,2,2,0,kw_442,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod)}
		},
	kw_444[15] = {
		{"box_behnken",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_BOX_BEHNKEN)},
		{"central_composite",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_CENTRAL_COMPOSITE)},
		{"fixed_seed",8,0,4,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"grid",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_GRID)},
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_LHS)},
		{"main_effects",8,0,5,0,0,0.,0.,0,N_mdm(true,mainEffectsFlag)},
		{"model_pointer",11,0,9,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"oa_lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_OA_LHS)},
		{"oas",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_OAS)},
		{"quality_metrics",8,0,6,0,0,0.,0.,0,N_mdm(true,volQualityFlag)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_RANDOM)},
		{"samples",9,0,2,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"seed",0x19,0,3,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"symbols",9,0,8,0,0,0.,0.,0,N_mdm(int,numSymbols)},
		{"variance_based_decomp",8,2,7,0,kw_443,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_445[7] = {
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"options_file",11,0,6,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)},
		{"solution_accuracy",2,0,5,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,5,0,0,0.,0.,0,N_mdm(Real,solnTarget)},
		{"variable_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,threshStepLength)}
		},
	kw_446[3] = {
		{"max_function_evaluations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"model_pointer",11,0,3,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,2,0,0,0.,0.,0,N_mdm(true,methodScaling)}
		},
	kw_447[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_448[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_449[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_450[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_451[7] = {
		{"constraint_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,4,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_452[2] = {
		{"blocking",8,0,1,1,0,0.,0.,0,N_mdm(type,evalSynchronize_BLOCKING_SYNCHRONIZATION)},
		{"nonblocking",8,0,1,1,0,0.,0.,0,N_mdm(type,evalSynchronize_NONBLOCKING_SYNCHRONIZATION)}
		},
	kw_453[2] = {
		{"exploration",0x29,0,1,0,0,0.,0.,0,N_mdm(int,batchSizeExplore)},
		{"synchronization",8,2,2,0,kw_452}
		},
	kw_454[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_455[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_454,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_456[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_457[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_456}
		},
	kw_458[2] = {
		{"export_model",8,2,1,0,kw_457,0.,0.,0,N_mdm(true,exportSurrogate)},
		{"options_file",11,0,2,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)}
		},
	kw_459[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_460[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_459}
		},
	kw_461[1] = {
		{"export_model",8,2,1,0,kw_460,0.,0.,0,N_mdm(true,exportSurrogate)}
		},
	kw_462[3] = {
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"experimental",8,2,1,1,kw_458,0.,0.,0,N_mdm(type,emulatorType_EXPGP_EMULATOR)},
		{"surfpack",8,1,1,1,kw_461,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_463[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_464[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_463,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_465[14] = {
		{"batch_size",0x29,2,3,0,kw_453,1.,0.,0,N_mdm(int,batchSize)},
		{"convergence_tolerance",10,0,5,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"export_approx_points_file",11,3,10,0,kw_455,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,10,0,kw_455,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gaussian_process",8,3,7,0,kw_462},
		{"import_build_points_file",11,4,9,0,kw_464,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,9,0,kw_464,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"initial_samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"kriging",0,3,7,0,kw_462,0.,0.,-4},
		{"max_iterations",0x29,0,4,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,11,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"use_derivatives",8,0,8,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"x_conv_tol",10,0,6,0,0,0.,0.,0,N_mdm(Real,xConvTol)}
		},
	kw_466[3] = {
		{"grid",8,0,1,1,0,0.,0.,0,N_mdm(lit,trialType_grid)},
		{"halton",8,0,1,1,0,0.,0.,0,N_mdm(lit,trialType_halton)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(lit,trialType_random)}
		},
	kw_467[1] = {
		{"num_bins",9,0,1,0,0,0.,0.,0,N_mdm(int,vbdViaSamplingNumBins)}
		},
	kw_468[2] = {
		{"binned",8,1,1,1,kw_467,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_BINNED)},
		{"pick_and_freeze",8,0,1,1,0,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_PICK_AND_FREEZE)}
		},
	kw_469[2] = {
		{"drop_tolerance",10,0,1,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"vbd_sampling_method",8,2,2,0,kw_468,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod)}
		},
	kw_470[10] = {
		{"fixed_seed",8,0,3,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"latinize",8,0,4,0,0,0.,0.,0,N_mdm(true,latinizeFlag)},
		{"max_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"num_trials",9,0,8,0,0,0.,0.,0,N_mdm(int,numTrials)},
		{"quality_metrics",8,0,5,0,0,0.,0.,0,N_mdm(true,volQualityFlag)},
		{"samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"trial_type",8,3,7,0,kw_466},
		{"variance_based_decomp",8,2,6,0,kw_469,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_471[1] = {
		{"num_bins",9,0,1,0,0,0.,0.,0,N_mdm(int,vbdViaSamplingNumBins)}
		},
	kw_472[2] = {
		{"binned",8,1,1,1,kw_471,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_BINNED)},
		{"pick_and_freeze",8,0,1,1,0,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_PICK_AND_FREEZE)}
		},
	kw_473[2] = {
		{"drop_tolerance",10,0,1,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"vbd_sampling_method",8,2,2,0,kw_472,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod)}
		},
	kw_474[12] = {
		{"fixed_sequence",8,0,6,0,0,0.,0.,0,N_mdm(true,fixedSequenceFlag)},
		{"halton",8,0,1,1,0,0.,0.,0,N_mdm(utype,methodName_FSU_HALTON)},
		{"hammersley",8,0,1,1,0,0.,0.,0,N_mdm(utype,methodName_FSU_HAMMERSLEY)},
		{"latinize",8,0,2,0,0,0.,0.,0,N_mdm(true,latinizeFlag)},
		{"max_iterations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,11,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"prime_base",13,0,9,0,0,0.,0.,0,N_mdm(ivec,primeBase)},
		{"quality_metrics",8,0,3,0,0,0.,0.,0,N_mdm(true,volQualityFlag)},
		{"samples",9,0,5,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"sequence_leap",13,0,8,0,0,0.,0.,0,N_mdm(ivec,sequenceLeap)},
		{"sequence_start",13,0,7,0,0,0.,0.,0,N_mdm(ivec,sequenceStart)},
		{"variance_based_decomp",8,2,4,0,kw_473,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_475[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_476[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_477[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_476,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_478[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_479[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_480[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_481[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_480,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_482[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_483[1] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)}
		},
	kw_484[5] = {
		{"increment_max_order",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_MAX_ORDER_ADVANCEMENT)},
		{"increment_max_rank",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_MAX_RANK_ADVANCEMENT)},
		{"increment_max_rank_order",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_MAX_RANK_ORDER_ADVANCEMENT)},
		{"increment_start_order",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_START_ORDER_ADVANCEMENT)},
		{"increment_start_rank",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_START_RANK_ADVANCEMENT)}
		},
	kw_485[1] = {
		{"uniform",8,5,1,1,kw_484,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_486[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_487[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_488[1] = {
		{"l2_penalty",10,0,1,1,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)}
		},
	kw_489[2] = {
		{"ls",8,0,1,1,0,0.,0.,0,N_mdm(type,regressionType_FT_LS)},
		{"rls2",8,1,1,1,kw_488,0.,0.,0,N_mdm(type,regressionType_FT_RLS2)}
		},
	kw_490[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_491[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_492[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_491}
		},
	kw_493[2] = {
		{"compute",8,4,2,0,kw_492},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_494[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_495[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_496[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_497[47] = {
		{"adapt_order",8,0,15,0,0,0.,0.,0,N_mdm(true,adaptOrder)},
		{"adapt_rank",8,0,20,0,0,0.,0.,0,N_mdm(true,adaptRank)},
		{"arithmetic_tolerance",10,0,13,0,0,0.,0.,0,N_mdm(Real,statsRoundingTol)},
		{"collocation_points",9,0,11,1,0,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"collocation_ratio",10,0,11,1,0,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,35,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"distribution",8,2,33,0,kw_475},
		{"export_approx_points_file",11,3,37,0,kw_477,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,37,0,kw_477,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,28,0,kw_478},
		{"fixed_seed",8,0,39,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,35,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,32,0,kw_479,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,36,0,kw_481,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"kick_order",0x19,0,16,0,0,0.,0.,0,N_mdm(ushint,kickOrder)},
		{"kick_rank",0x19,0,21,0,0,0.,0.,0,N_mdm(sizet,kickRank)},
		{"max_cross_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(int,maxCrossIterations)},
		{"max_cv_order_candidates",0x29,0,18,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"max_cv_rank_candidates",0x29,0,23,0,0,0.,0.,0,N_mdm(sizet,maxCVRankCandidates)},
		{"max_order",0x29,0,17,0,0,0.,0.,0,N_mdm(ushint,maxOrder)},
		{"max_rank",0x29,0,22,0,0,0.,0.,0,N_mdm(sizet,maxRank)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"max_solver_iterations",0x29,0,6,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"metric_scale",8,2,4,0,kw_482},
		{"model_pointer",11,0,40,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"order",0x21,1,14,0,kw_483,0.,0.,17,N_mdm(ushint,startOrder)},
		{"p_refinement",8,1,1,0,kw_485,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"probability_levels",14,1,30,0,kw_486,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,27,0,kw_487},
		{"rank",0x21,0,19,0,0,0.,0.,14,N_mdm(sizet,startRank)},
		{"regression_type",8,2,5,0,kw_489},
		{"reliability_levels",14,1,31,0,kw_490,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,29,0,kw_493,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"response_scaling",8,0,9,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"rng",8,2,26,0,kw_494},
		{"rounding_tolerance",10,0,12,0,0,0.,0.,0,N_mdm(Real,solverRoundingTol)},
		{"sample_refinement",0,4,27,0,kw_487,0.,0.,-8},
		{"sample_type",8,2,25,0,kw_495},
		{"samples",1,0,24,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,24,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,38,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"solver_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,solverTol)},
		{"start_order",0x29,1,14,0,kw_483,0.,0.,0,N_mdm(ushint,startOrder)},
		{"start_rank",0x29,0,19,0,0,0.,0.,0,N_mdm(sizet,startRank)},
		{"tensor_grid",8,0,10,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"variance_based_decomp",8,2,34,0,kw_496,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_498[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_499[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_500[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_499,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_501[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_502[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_503[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_502,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_504[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_505[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_506[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_505}
		},
	kw_507[2] = {
		{"compute",8,3,2,0,kw_506},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_508[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_509[15] = {
		{"build_samples",9,0,1,0,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"distribution",8,2,10,0,kw_498},
		{"export_approx_points_file",11,3,5,0,kw_500,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,5,0,kw_500,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gen_reliability_levels",14,1,9,0,kw_501,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_build_points_file",11,4,4,0,kw_503,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_503,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"max_iterations",0x29,0,6,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,8,0,kw_504,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"response_levels",14,2,7,0,kw_507,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,11,0,kw_508},
		{"samples",1,0,1,0,0,0.,0.,-12,N_mdm(int,buildSamples)},
		{"samples_on_emulator",9,0,3,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_510[4] = {
		{"max_function_evaluations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"model_pointer",11,0,4,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,3,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,1,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_511[4] = {
		{"max_function_evaluations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"model_pointer",11,0,4,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,3,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,1,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_512[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_513[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_514[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_513,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_515[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_516[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_515}
		},
	kw_517[2] = {
		{"export_model",8,2,1,0,kw_516,0.,0.,0,N_mdm(true,exportSurrogate)},
		{"options_file",11,0,2,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)}
		},
	kw_518[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_519[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_518}
		},
	kw_520[1] = {
		{"export_model",8,2,1,0,kw_519,0.,0.,0,N_mdm(true,exportSurrogate)}
		},
	kw_521[3] = {
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"experimental",8,2,1,1,kw_517,0.,0.,0,N_mdm(type,emulatorType_EXPGP_EMULATOR)},
		{"surfpack",8,1,1,1,kw_520,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_522[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_523[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_522,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_524[7] = {
		{"export_approx_points_file",11,3,4,0,kw_514,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,4,0,kw_514,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gaussian_process",8,3,1,0,kw_521},
		{"import_build_points_file",11,4,3,0,kw_523,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,3,0,kw_523,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"kriging",0,3,1,0,kw_521,0.,0.,-3},
		{"use_derivatives",8,0,2,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_525[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_526[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_527[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_528[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_527}
		},
	kw_529[2] = {
		{"compute",8,3,2,0,kw_528},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_530[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_531[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_532[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_531,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_533[1] = {
		{"options_file",11,0,1,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)}
		},
	kw_534[3] = {
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"experimental",8,1,1,1,kw_533,0.,0.,0,N_mdm(type,emulatorType_EXPGP_EMULATOR)},
		{"surfpack",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_535[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_536[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_535,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_537[7] = {
		{"export_approx_points_file",11,3,4,0,kw_532,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,4,0,kw_532,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gaussian_process",8,3,1,0,kw_534},
		{"import_build_points_file",11,4,3,0,kw_536,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,3,0,kw_536,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"kriging",0,3,1,0,kw_534,0.,0.,-3},
		{"use_derivatives",8,0,2,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_538[12] = {
		{"distribution",8,2,7,0,kw_512},
		{"ea",8,0,3,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_EA)},
		{"ego",8,7,3,0,kw_524,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_EGO)},
		{"gen_reliability_levels",14,1,6,0,kw_525,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"lhs",8,0,3,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_LHS)},
		{"model_pointer",11,0,9,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,5,0,kw_526,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"response_levels",14,2,4,0,kw_529,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,8,0,kw_530},
		{"samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"sbgo",8,7,3,0,kw_537,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_SBGO)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_539[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_540[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_539,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_541[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_542[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_541}
		},
	kw_543[2] = {
		{"export_model",8,2,1,0,kw_542,0.,0.,0,N_mdm(true,exportSurrogate)},
		{"options_file",11,0,2,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)}
		},
	kw_544[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_545[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_544}
		},
	kw_546[1] = {
		{"export_model",8,2,1,0,kw_545,0.,0.,0,N_mdm(true,exportSurrogate)}
		},
	kw_547[3] = {
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"experimental",8,2,1,1,kw_543,0.,0.,0,N_mdm(type,emulatorType_EXPGP_EMULATOR)},
		{"surfpack",8,1,1,1,kw_546,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_548[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_549[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_548,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_550[7] = {
		{"export_approx_points_file",11,3,4,0,kw_540,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,4,0,kw_540,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gaussian_process",8,3,1,0,kw_547},
		{"import_build_points_file",11,4,3,0,kw_549,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,3,0,kw_549,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"kriging",0,3,1,0,kw_547,0.,0.,-3},
		{"use_derivatives",8,0,2,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_551[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_552[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_553[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_552,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_554[1] = {
		{"options_file",11,0,1,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)}
		},
	kw_555[3] = {
		{"dakota",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"experimental",8,1,1,1,kw_554,0.,0.,0,N_mdm(type,emulatorType_EXPGP_EMULATOR)},
		{"surfpack",8,0,1,1,0,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)}
		},
	kw_556[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_557[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_556,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_558[7] = {
		{"export_approx_points_file",11,3,4,0,kw_553,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,4,0,kw_553,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gaussian_process",8,3,1,0,kw_555},
		{"import_build_points_file",11,4,3,0,kw_557,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,3,0,kw_557,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"kriging",0,3,1,0,kw_555,0.,0.,-3},
		{"use_derivatives",8,0,2,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_559[11] = {
		{"convergence_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"ea",8,0,6,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_EA)},
		{"ego",8,7,6,0,kw_550,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_EGO)},
		{"lhs",8,0,6,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_LHS)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,8,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"rng",8,2,7,0,kw_551},
		{"samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"sbgo",8,7,6,0,kw_558,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_SBGO)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_560[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_561[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_562[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_561}
		},
	kw_563[2] = {
		{"export_model",8,2,1,0,kw_562,0.,0.,0,N_mdm(true,exportSurrogate)},
		{"options_file",11,0,2,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)}
		},
	kw_564[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_565[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_564,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_566[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_567[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_568[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_567,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_569[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_570[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_571[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_570}
		},
	kw_572[2] = {
		{"compute",8,3,2,0,kw_571},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_573[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_574[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_575[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mdm(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_574}
		},
	kw_576[1] = {
		{"export_model",8,2,1,0,kw_575,0.,0.,0,N_mdm(true,exportSurrogate)}
		},
	kw_577[22] = {
		{"convergence_tolerance",10,0,14,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"dakota",8,0,3,0,0,0.,0.,0,N_mdm(type,emulatorType_GP_EMULATOR)},
		{"distribution",8,2,12,0,kw_560},
		{"experimental",8,2,3,0,kw_563,0.,0.,0,N_mdm(type,emulatorType_EXPGP_EMULATOR)},
		{"export_approx_points_file",11,3,5,0,kw_565,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,5,0,kw_565,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"gen_reliability_levels",14,1,11,0,kw_566,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_build_points_file",11,4,4,0,kw_568,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_568,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"initial_samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"max_iterations",0x29,0,13,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,15,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,10,0,kw_569,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"response_levels",14,2,9,0,kw_572,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,8,0,kw_573},
		{"seed",0x19,0,7,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"surfpack",8,1,3,0,kw_576,0.,0.,0,N_mdm(type,emulatorType_KRIGING_EMULATOR)},
		{"u_gaussian_process",8,0,2,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_EGRA_U)},
		{"u_kriging",0,0,2,1,0,0.,0.,-1,N_mdm(utype,subMethod_SUBMETHOD_EGRA_U)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"x_gaussian_process",8,0,2,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_EGRA_X)},
		{"x_kriging",0,0,2,1,0,0.,0.,-1,N_mdm(utype,subMethod_SUBMETHOD_EGRA_X)}
		},
	kw_578[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_PEER_SCHEDULING)}
		},
	kw_579[1] = {
		{"model_pointer_list",15,0,1,0,0,0.,0.,0,N_mdm(strL,hybridModelPointers)}
		},
	kw_580[5] = {
		{"iterator_scheduling",8,2,3,0,kw_578},
		{"iterator_servers",0x19,0,2,0,0,0.,0.,0,N_mdm(int,iteratorServers)},
		{"method_name_list",15,1,1,1,kw_579,0.,0.,0,N_mdm(strL,hybridMethodNames)},
		{"method_pointer_list",15,0,1,1,0,0.,0.,0,N_mdm(strL,hybridMethodPointers)},
		{"processors_per_iterator",0x19,0,4,0,0,0.,0.,0,N_mdm(int,procsPerIterator)}
		},
	kw_581[1] = {
		{"global_model_pointer",11,0,1,0,0,0.,0.,0,N_mdm(str,hybridGlobalModelPointer)}
		},
	kw_582[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_PEER_SCHEDULING)}
		},
	kw_583[1] = {
		{"local_model_pointer",11,0,1,0,0,0.,0.,0,N_mdm(str,hybridLocalModelPointer)}
		},
	kw_584[8] = {
		{"global_method_name",11,1,1,1,kw_581,0.,0.,0,N_mdm(str,hybridGlobalMethodName)},
		{"global_method_pointer",11,0,1,1,0,0.,0.,0,N_mdm(str,hybridGlobalMethodPointer)},
		{"iterator_scheduling",8,2,5,0,kw_582},
		{"iterator_servers",0x19,0,4,0,0,0.,0.,0,N_mdm(int,iteratorServers)},
		{"local_method_name",11,1,2,2,kw_583,0.,0.,0,N_mdm(str,hybridLocalMethodName)},
		{"local_method_pointer",11,0,2,2,0,0.,0.,0,N_mdm(str,hybridLocalMethodPointer)},
		{"local_search_probability",10,0,3,0,0,0.,0.,0,N_mdm(Real,hybridLSProb)},
		{"processors_per_iterator",0x19,0,6,0,0,0.,0.,0,N_mdm(int,procsPerIterator)}
		},
	kw_585[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_PEER_SCHEDULING)}
		},
	kw_586[1] = {
		{"model_pointer_list",15,0,1,0,0,0.,0.,0,N_mdm(strL,hybridModelPointers)}
		},
	kw_587[5] = {
		{"iterator_scheduling",8,2,3,0,kw_585},
		{"iterator_servers",0x19,0,2,0,0,0.,0.,0,N_mdm(int,iteratorServers)},
		{"method_name_list",15,1,1,1,kw_586,0.,0.,0,N_mdm(strL,hybridMethodNames)},
		{"method_pointer_list",15,0,1,1,0,0.,0.,0,N_mdm(strL,hybridMethodPointers)},
		{"processors_per_iterator",0x19,0,4,0,0,0.,0.,0,N_mdm(int,procsPerIterator)}
		},
	kw_588[5] = {
		{"collaborative",8,5,1,1,kw_580,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_COLLABORATIVE)},
		{"coupled",0,8,1,1,kw_584,0.,0.,1,N_mdm(utype,subMethod_SUBMETHOD_EMBEDDED)},
		{"embedded",8,8,1,1,kw_584,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_EMBEDDED)},
		{"sequential",8,5,1,1,kw_587,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_SEQUENTIAL)},
		{"uncoupled",0,5,1,1,kw_587,0.,0.,-1,N_mdm(utype,subMethod_SUBMETHOD_SEQUENTIAL)}
		},
	kw_589[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_590[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_591[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_592[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_593[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_592}
		},
	kw_594[2] = {
		{"compute",8,3,2,0,kw_593},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_595[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_596[15] = {
		{"adapt_import",8,0,3,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"convergence_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"distribution",8,2,10,0,kw_589},
		{"gen_reliability_levels",14,1,9,0,kw_590,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import",8,0,3,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"initial_samples",1,0,1,0,0,0.,0.,8,N_mdm(int,numSamples)},
		{"max_iterations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"mm_adapt_import",8,0,3,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,8,0,kw_591,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"refinement_samples",13,0,4,0,0,0.,0.,0,N_mdm(ivec,refineSamples)},
		{"response_levels",14,2,7,0,kw_594,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,11,0,kw_595},
		{"samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_597[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,pstudyFileFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,pstudyFileFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,pstudyFileFormat_TABULAR_IFACE_ID)}
		},
	kw_598[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,pstudyFileActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,pstudyFileFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_597,0.,0.,0,N_mdm(utype,pstudyFileFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,pstudyFileFormat_TABULAR_NONE)}
		},
	kw_599[3] = {
		{"import_points_file",11,4,1,1,kw_598,0.,0.,0,N_mdm(str,pstudyFilename)},
		{"list_of_points",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,listOfPoints)},
		{"model_pointer",11,0,2,0,0,0.,0.,0,N_mdm(str,modelPointer)}
		},
	kw_600[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_601[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_602[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_603[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_604[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_603}
		},
	kw_605[2] = {
		{"compute",8,3,2,0,kw_604},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_606[7] = {
		{"distribution",8,2,5,0,kw_600},
		{"gen_reliability_levels",14,1,4,0,kw_601,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"model_pointer",11,0,6,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"nip",8,0,1,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"probability_levels",14,1,3,0,kw_602,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"response_levels",14,2,2,0,kw_605,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"sqp",8,0,1,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)}
		},
	kw_607[4] = {
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"model_pointer",11,0,3,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"nip",8,0,1,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"sqp",8,0,1,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)}
		},
	kw_608[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_609[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_610[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_611[5] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)},
		{"seed",0x19,0,3,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_612[4] = {
		{"first_order",8,0,1,1,0,0.,0.,0,N_mdm(lit,reliabilityIntegration_first_order)},
		{"probability_refinement",8,5,2,0,kw_611},
		{"sample_refinement",0,5,2,0,kw_611,0.,0.,-1},
		{"second_order",8,0,1,1,0,0.,0.,0,N_mdm(lit,reliabilityIntegration_second_order)}
		},
	kw_613[12] = {
		{"integration",8,4,3,0,kw_612},
		{"nip",8,0,2,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"no_approx",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_NO_APPROX)},
		{"sqp",8,0,2,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)},
		{"u_multi_point",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_QMEA_U)},
		{"u_taylor_mean",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_AMV_U)},
		{"u_taylor_mpp",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_AMV_PLUS_U)},
		{"u_two_point",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_TANA_U)},
		{"x_multi_point",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_QMEA_X)},
		{"x_taylor_mean",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_AMV_X)},
		{"x_taylor_mpp",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_AMV_PLUS_X)},
		{"x_two_point",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_TANA_X)}
		},
	kw_614[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_615[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_616[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_617[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_616}
		},
	kw_618[2] = {
		{"compute",8,4,2,0,kw_617},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_619[10] = {
		{"convergence_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"distribution",8,2,6,0,kw_608},
		{"final_moments",8,3,9,0,kw_609},
		{"gen_reliability_levels",14,1,5,0,kw_610,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"max_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"mpp_search",8,12,1,0,kw_613},
		{"probability_levels",14,1,3,0,kw_614,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"reliability_levels",14,1,4,0,kw_615,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,2,0,kw_618,0.,0.,0,N_mdm(resplevs,responseLevels)}
		},
	kw_620[2] = {
		{"inform_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,useSurrogate_inform_search)},
		{"optimize",8,0,1,1,0,0.,0.,0,N_mdm(lit,useSurrogate_optimize)}
		},
	kw_621[14] = {
		{"display_all_evaluations",8,0,9,0,0,0.,0.,0,N_mdm(true,showAllEval)},
		{"display_format",11,0,6,0,0,0.,0.,0,N_mdm(str,displayFormat)},
		{"function_precision",10,0,3,0,0,0.,0.,0,N_mdm(Real,functionPrecision)},
		{"history_file",11,0,5,0,0,0.,0.,0,N_mdm(str,historyFile)},
		{"initial_delta",10,0,1,0,0,0.,0.,0,N_mdm(Real,initMeshSize)},
		{"max_function_evaluations",0x29,0,12,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,11,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,14,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"neighbor_order",0x19,0,8,0,0,0.,0.,0,N_mdm(int,neighborOrder)},
		{"scaling",8,0,13,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,4,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"use_surrogate",8,2,10,0,kw_620},
		{"variable_neighborhood_search",10,0,7,0,0,0.,0.,0,N_mdm(Real,vns)},
		{"variable_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,minMeshSize)}
		},
	kw_622[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_623[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_622,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_624[6] = {
		{"competed_local",8,0,2,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL_OPTPP)},
		{"fallback",8,0,1,0,0,0.,0.,0,N_mdm(utype,numericalSolveMode_NUMERICAL_FALLBACK)},
		{"global_local",8,0,2,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_DIRECT_NPSOL_OPTPP)},
		{"nip",8,0,2,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"override",8,0,1,0,0,0.,0.,0,N_mdm(utype,numericalSolveMode_NUMERICAL_OVERRIDE)},
		{"sqp",8,0,2,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)}
		},
	kw_625[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_626[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_627[3] = {
		{"full_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_FULL_GRAPH_RECURSION)},
		{"model_selection",8,0,1,0,0,0.,0.,0,N_mdm(type,modelSelectType_ALL_MODEL_COMBINATIONS)},
		{"no_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_NO_GRAPH_RECURSION)}
		},
	kw_628[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_629[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_630[2] = {
		{"distribution",8,2,2,0,kw_628},
		{"final_moments",8,3,1,0,kw_629}
		},
	kw_631[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_630,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_632[1] = {
		{"final_statistics",8,2,1,0,kw_631}
		},
	kw_633[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_634[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_635[2] = {
		{"distribution",8,2,2,0,kw_633},
		{"final_moments",8,3,1,0,kw_634}
		},
	kw_636[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_635,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_637[3] = {
		{"factor_sequence",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,relaxFactorSequence)},
		{"fixed_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxFixedFactor)},
		{"recursive_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxRecursiveFactor)}
		},
	kw_638[2] = {
		{"final_statistics",8,2,2,0,kw_636},
		{"relaxation",8,3,1,0,kw_637}
		},
	kw_639[4] = {
		{"offline_pilot",8,1,1,1,kw_632,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT)},
		{"offline_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT_PROJECTION)},
		{"online_pilot",8,2,1,1,kw_638,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT)},
		{"online_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT_PROJECTION)}
		},
	kw_640[14] = {
		{"convergence_tolerance",10,0,9,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"export_sample_sequence",8,3,8,0,kw_623,0.,0.,0,N_mdm(true,exportSampleSeqFlag)},
		{"fixed_seed",8,0,2,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"initial_samples",5,0,3,0,0,0.,0.,5,N_mdm(szarray,pilotSamples)},
		{"max_function_evaluations",0x29,0,11,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,13,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"numerical_solve",8,6,5,0,kw_624},
		{"pilot_samples",13,0,3,0,0,0.,0.,0,N_mdm(szarray,pilotSamples)},
		{"rng",8,2,12,0,kw_625},
		{"sample_type",8,2,7,0,kw_626},
		{"search_model_graphs",8,3,6,0,kw_627},
		{"seed_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solution_mode",8,4,4,0,kw_639}
		},
	kw_641[2] = {
		{"optimization",8,0,2,0,0,0.,0.,0,N_mdm(true,useTargetVarianceOptimizationFlag)},
		{"scalarization_response_mapping",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,scalarizationRespCoeffs)}
		},
	kw_642[1] = {
		{"optimization",8,0,1,0,0,0.,0.,0,N_mdm(true,useTargetVarianceOptimizationFlag)}
		},
	kw_643[1] = {
		{"optimization",8,0,1,0,0,0.,0.,0,N_mdm(true,useTargetVarianceOptimizationFlag)}
		},
	kw_644[4] = {
		{"mean",8,0,1,1,0,0.,0.,0,N_mdm(type,allocationTarget_TARGET_MEAN)},
		{"scalarization",8,2,1,1,kw_641,0.,0.,0,N_mdm(type,allocationTarget_TARGET_SCALARIZATION)},
		{"standard_deviation",8,1,1,1,kw_642,0.,0.,0,N_mdm(type,allocationTarget_TARGET_SIGMA)},
		{"variance",8,1,1,1,kw_643,0.,0.,0,N_mdm(type,allocationTarget_TARGET_VARIANCE)}
		},
	kw_645[2] = {
		{"cost_constraint",8,0,1,1,0,0.,0.,0,N_mdm(type,convergenceToleranceTarget_CONVERGENCE_TOLERANCE_TARGET_COST_CONSTRAINT)},
		{"variance_constraint",8,0,1,1,0,0.,0.,0,N_mdm(type,convergenceToleranceTarget_CONVERGENCE_TOLERANCE_TARGET_VARIANCE_CONSTRAINT)}
		},
	kw_646[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(type,convergenceToleranceType_CONVERGENCE_TOLERANCE_TYPE_ABSOLUTE)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(type,convergenceToleranceType_CONVERGENCE_TOLERANCE_TYPE_RELATIVE)}
		},
	kw_647[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_648[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_647,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_649[2] = {
		{"max",8,0,1,1,0,0.,0.,0,N_mdm(type,qoiAggregation_QOI_AGGREGATION_MAX)},
		{"sum",8,0,1,1,0,0.,0.,0,N_mdm(type,qoiAggregation_QOI_AGGREGATION_SUM)}
		},
	kw_650[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_651[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_652[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_653[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_654[2] = {
		{"distribution",8,2,2,0,kw_652},
		{"final_moments",8,3,1,0,kw_653}
		},
	kw_655[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_654,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_656[1] = {
		{"final_statistics",8,2,1,0,kw_655}
		},
	kw_657[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_658[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_659[2] = {
		{"distribution",8,2,2,0,kw_657},
		{"final_moments",8,3,1,0,kw_658}
		},
	kw_660[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_659,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_661[3] = {
		{"factor_sequence",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,relaxFactorSequence)},
		{"fixed_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxFixedFactor)},
		{"recursive_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxRecursiveFactor)}
		},
	kw_662[2] = {
		{"final_statistics",8,2,2,0,kw_660},
		{"relaxation",8,3,1,0,kw_661}
		},
	kw_663[4] = {
		{"offline_pilot",8,1,1,1,kw_656,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT)},
		{"offline_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT_PROJECTION)},
		{"online_pilot",8,2,1,1,kw_662,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT)},
		{"online_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT_PROJECTION)}
		},
	kw_664[3] = {
		{"full_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_FULL_GRAPH_RECURSION)},
		{"model_selection",8,0,1,0,0,0.,0.,0,N_mdm(type,modelSelectType_ALL_MODEL_COMBINATIONS)},
		{"no_recursion",8,0,2,1,0,0.,0.,0,N_mdm(type,dagRecursionType_NO_GRAPH_RECURSION)}
		},
	kw_665[1] = {
		{"search_model_graphs",8,3,1,0,kw_664}
		},
	kw_666[17] = {
		{"allocation_target",8,4,8,0,kw_644},
		{"convergence_tolerance",10,0,10,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"convergence_tolerance_target",8,2,12,0,kw_645},
		{"convergence_tolerance_type",8,2,11,0,kw_646},
		{"export_sample_sequence",8,3,7,0,kw_648,0.,0.,0,N_mdm(true,exportSampleSeqFlag)},
		{"fixed_seed",8,0,2,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"initial_samples",5,0,3,0,0,0.,0.,4,N_mdm(szarray,pilotSamples)},
		{"max_function_evaluations",0x29,0,14,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,13,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,16,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"pilot_samples",13,0,3,0,0,0.,0.,0,N_mdm(szarray,pilotSamples)},
		{"qoi_aggregation",8,2,9,0,kw_649},
		{"rng",8,2,15,0,kw_650},
		{"sample_type",8,2,5,0,kw_651},
		{"seed_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solution_mode",8,4,4,0,kw_663},
		{"weighted",8,1,6,0,kw_665,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_WEIGHTED_MLMC)}
		},
	kw_667[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_668[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_667,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_669[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_670[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_671[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_672[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_673[2] = {
		{"distribution",8,2,2,0,kw_671},
		{"final_moments",8,3,1,0,kw_672}
		},
	kw_674[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_673,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_675[1] = {
		{"final_statistics",8,2,1,0,kw_674}
		},
	kw_676[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_677[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_678[2] = {
		{"distribution",8,2,2,0,kw_676},
		{"final_moments",8,3,1,0,kw_677}
		},
	kw_679[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_678,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_680[3] = {
		{"factor_sequence",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,relaxFactorSequence)},
		{"fixed_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxFixedFactor)},
		{"recursive_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxRecursiveFactor)}
		},
	kw_681[2] = {
		{"final_statistics",8,2,2,0,kw_679},
		{"relaxation",8,3,1,0,kw_680}
		},
	kw_682[4] = {
		{"offline_pilot",8,1,1,1,kw_675,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT)},
		{"offline_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT_PROJECTION)},
		{"online_pilot",8,2,1,1,kw_681,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT)},
		{"online_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT_PROJECTION)}
		},
	kw_683[12] = {
		{"convergence_tolerance",10,0,7,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"export_sample_sequence",8,3,6,0,kw_668,0.,0.,0,N_mdm(true,exportSampleSeqFlag)},
		{"fixed_seed",8,0,2,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"initial_samples",5,0,3,0,0,0.,0.,4,N_mdm(szarray,pilotSamples)},
		{"max_function_evaluations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,11,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"pilot_samples",13,0,3,0,0,0.,0.,0,N_mdm(szarray,pilotSamples)},
		{"rng",8,2,10,0,kw_669},
		{"sample_type",8,2,5,0,kw_670},
		{"seed_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solution_mode",8,4,4,0,kw_682}
		},
	kw_684[3] = {
		{"metric_tracker",8,0,1,1,0,0.,0.,0,N_mdm(lit,convergenceType_metric_tracker)},
		{"num_generations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,numGenerations)},
		{"percent_change",10,0,2,0,0,0.,0.,0,N_mdm(Realz,convergenceTolerance)}
		},
	kw_685[2] = {
		{"num_offspring",0x19,0,2,0,0,0.,0.,0,N_mdm(sizet,numOffspring)},
		{"num_parents",0x19,0,1,0,0,0.,0.,0,N_mdm(sizet,numParents)}
		},
	kw_686[5] = {
		{"crossover_rate",10,0,2,0,0,0.,0.,0,N_mdm(litz,TYPE_DATA_crossoverType_null_crossover)},
		{"multi_point_binary",9,0,1,1,0,0.,0.,0,N_mdm(ilit2p,TYPE_DATA_crossoverType_multi_point_binary)},
		{"multi_point_parameterized_binary",9,0,1,1,0,0.,0.,0,N_mdm(ilit2p,TYPE_DATA_crossoverType_multi_point_parameterized_binary)},
		{"multi_point_real",9,0,1,1,0,0.,0.,0,N_mdm(ilit2p,TYPE_DATA_crossoverType_multi_point_real)},
		{"shuffle_random",8,2,1,1,kw_685,0.,0.,0,N_mdm(litc,TYPE_DATA_crossoverType_shuffle_random)}
		},
	kw_687[2] = {
		{"domination_count",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessType_domination_count)},
		{"layer_rank",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessType_layer_rank)}
		},
	kw_688[3] = {
		{"flat_file",11,0,1,1,0,0.,0.,0,N_mdm(slit2,TYPE_DATA_initializationType_flat_file)},
		{"simple_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,initializationType_random)},
		{"unique_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,initializationType_unique_random)}
		},
	kw_689[1] = {
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real01,mutationScale)}
		},
	kw_690[1] = {
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real01,mutationScale)}
		},
	kw_691[1] = {
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real01,mutationScale)}
		},
	kw_692[6] = {
		{"bit_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,mutationType_bit_random)},
		{"mutation_rate",10,0,2,0,0,0.,0.,0,N_mdm(litz,TYPE_DATA_mutationType_null_mutation)},
		{"offset_cauchy",8,1,1,1,kw_689,0.,0.,0,N_mdm(litc,TYPE_DATA_mutationType_offset_cauchy)},
		{"offset_normal",8,1,1,1,kw_690,0.,0.,0,N_mdm(litc,TYPE_DATA_mutationType_offset_normal)},
		{"offset_uniform",8,1,1,1,kw_691,0.,0.,0,N_mdm(litc,TYPE_DATA_mutationType_offset_uniform)},
		{"replace_uniform",8,0,1,1,0,0.,0.,0,N_mdm(lit,mutationType_replace_uniform)}
		},
	kw_693[1] = {
		{"num_designs",0x29,0,1,0,0,2.,0.,0,N_mdm(sizet,numDesigns)}
		},
	kw_694[3] = {
		{"distance",14,0,1,1,0,0.,0.,0,N_mdm(RealLlit,TYPE_DATA_nichingType_distance)},
		{"max_designs",14,1,1,1,kw_693,0.,0.,0,N_mdm(RealLlit,TYPE_DATA_nichingType_max_designs)},
		{"radial",14,0,1,1,0,0.,0.,0,N_mdm(RealLlit,TYPE_DATA_nichingType_radial)}
		},
	kw_695[1] = {
		{"orthogonal_distance",14,0,1,1,0,0.,0.,0,N_mdm(RealLlit,TYPE_DATA_postProcessorType_distance_postprocessor)}
		},
	kw_696[2] = {
		{"shrinkage_fraction",10,0,1,0,0,0.,0.,0,N_mdm(Real01,shrinkagePercent)},
		{"shrinkage_percentage",2,0,1,0,0,0.,0.,-1,N_mdm(Real01,shrinkagePercent)}
		},
	kw_697[4] = {
		{"below_limit",10,2,1,1,kw_696,0.,0.,0,N_mdm(litp,TYPE_DATA_replacementType_below_limit)},
		{"elitist",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_elitist)},
		{"roulette_wheel",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_roulette_wheel)},
		{"unique_roulette_wheel",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_unique_roulette_wheel)}
		},
	kw_698[17] = {
		{"convergence_tolerance",10,0,16,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"convergence_type",8,3,4,0,kw_684},
		{"crossover_type",8,5,13,0,kw_686},
		{"fitness_type",8,2,1,0,kw_687},
		{"initialization_type",8,3,12,0,kw_688},
		{"log_file",11,0,10,0,0,0.,0.,0,N_mdm(str,logFile)},
		{"max_function_evaluations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,6,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,17,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"mutation_type",8,6,14,0,kw_692},
		{"niching_type",8,3,3,0,kw_694},
		{"population_size",0x29,0,9,0,0,0.,0.,0,N_mdm(int,populationSize)},
		{"postprocessor_type",8,1,5,0,kw_695},
		{"print_each_pop",8,0,11,0,0,0.,0.,0,N_mdm(true,printPopFlag)},
		{"replacement_type",8,4,2,0,kw_697},
		{"scaling",8,0,8,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,15,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_699[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_PEER_SCHEDULING)}
		},
	kw_700[1] = {
		{"model_pointer",11,0,1,0,0,0.,0.,0,N_mdm(str,subModelPointer)}
		},
	kw_701[1] = {
		{"seed",9,0,1,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_702[7] = {
		{"iterator_scheduling",8,2,5,0,kw_699},
		{"iterator_servers",0x19,0,4,0,0,0.,0.,0,N_mdm(int,iteratorServers)},
		{"method_name",11,1,1,1,kw_700,0.,0.,0,N_mdm(str,subMethodName)},
		{"method_pointer",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodPointer)},
		{"processors_per_iterator",0x19,0,6,0,0,0.,0.,0,N_mdm(int,procsPerIterator)},
		{"random_starts",9,1,2,0,kw_701,0.,0.,0,N_mdm(int,concurrentRandomJobs)},
		{"starting_points",14,0,3,0,0,0.,0.,0,N_mdm(RealDL,concurrentParameterSets)}
		},
	kw_703[2] = {
		{"model_pointer",11,0,2,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"partitions",13,0,1,1,0,0.,0.,0,N_mdm(usharray,varPartitions)}
		},
	kw_704[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_705[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_706[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_707[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_708[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_707,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_709[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_710[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_711[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_712[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_711,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_713[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_714[1] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)}
		},
	kw_715[5] = {
		{"increment_max_order",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_MAX_ORDER_ADVANCEMENT)},
		{"increment_max_rank",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_MAX_RANK_ADVANCEMENT)},
		{"increment_max_rank_order",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_MAX_RANK_ORDER_ADVANCEMENT)},
		{"increment_start_order",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_START_ORDER_ADVANCEMENT)},
		{"increment_start_rank",8,0,1,1,0,0.,0.,0,N_mdm(type,c3AdvanceType_START_RANK_ADVANCEMENT)}
		},
	kw_716[1] = {
		{"uniform",8,5,1,1,kw_715,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_717[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_718[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_719[1] = {
		{"l2_penalty",10,0,1,1,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)}
		},
	kw_720[2] = {
		{"ls",8,0,1,1,0,0.,0.,0,N_mdm(type,regressionType_FT_LS)},
		{"rls2",8,1,1,1,kw_719,0.,0.,0,N_mdm(type,regressionType_FT_RLS2)}
		},
	kw_721[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_722[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_723[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_722}
		},
	kw_724[2] = {
		{"compute",8,4,2,0,kw_723},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_725[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_726[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_727[2] = {
		{"active",8,0,1,1,0,0.,0.,0,N_mdm(type,statsMetricMode_ACTIVE_EXPANSION_STATS)},
		{"combined",8,0,1,1,0,0.,0.,0,N_mdm(type,statsMetricMode_COMBINED_EXPANSION_STATS)}
		},
	kw_728[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_729[51] = {
		{"adapt_order",8,0,19,0,0,0.,0.,0,N_mdm(true,adaptOrder)},
		{"adapt_rank",8,0,24,0,0,0.,0.,0,N_mdm(true,adaptRank)},
		{"allocation_control",8,1,6,0,kw_704},
		{"arithmetic_tolerance",10,0,9,0,0,0.,0.,0,N_mdm(Real,statsRoundingTol)},
		{"collocation_points_sequence",13,0,16,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"collocation_ratio",10,0,17,0,0,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,39,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,7,0,kw_705},
		{"distribution",8,2,37,0,kw_706},
		{"export_approx_points_file",11,3,41,0,kw_708,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,41,0,kw_708,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,32,0,kw_709},
		{"fixed_seed",8,0,43,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,39,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,36,0,kw_710,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,40,0,kw_712,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"kick_order",0x19,0,20,0,0,0.,0.,0,N_mdm(ushint,kickOrder)},
		{"kick_rank",0x19,0,25,0,0,0.,0.,0,N_mdm(sizet,kickRank)},
		{"max_cross_iterations",0x29,0,12,0,0,0.,0.,0,N_mdm(int,maxCrossIterations)},
		{"max_cv_order_candidates",0x29,0,22,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"max_cv_rank_candidates",0x29,0,27,0,0,0.,0.,0,N_mdm(sizet,maxCVRankCandidates)},
		{"max_order",0x29,0,21,0,0,0.,0.,0,N_mdm(ushint,maxOrder)},
		{"max_rank",0x29,0,26,0,0,0.,0.,0,N_mdm(sizet,maxRank)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"max_solver_iterations",0x29,0,11,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"metric_scale",8,2,4,0,kw_713},
		{"model_pointer",11,0,44,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"order_sequence",5,1,18,0,kw_714,0.,0.,18,N_mdm(usharray,startOrderSeq)},
		{"p_refinement",8,1,1,0,kw_716,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"pilot_samples",5,0,16,0,0,0.,0.,-26,N_mdm(szarray,collocationPointsSeq)},
		{"probability_levels",14,1,34,0,kw_717,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,31,0,kw_718},
		{"rank_sequence",5,0,23,0,0,0.,0.,14,N_mdm(szarray,startRankSeq)},
		{"regression_type",8,2,10,0,kw_720},
		{"reliability_levels",14,1,35,0,kw_721,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,33,0,kw_724,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"response_scaling",8,0,14,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"rng",8,2,30,0,kw_725},
		{"rounding_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,solverRoundingTol)},
		{"sample_refinement",0,4,31,0,kw_718,0.,0.,-8},
		{"sample_type",8,2,29,0,kw_726},
		{"samples",1,0,28,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,28,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed_sequence",13,0,42,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solver_tolerance",10,0,13,0,0,0.,0.,0,N_mdm(Real,solverTol)},
		{"start_order_sequence",13,1,18,0,kw_714,0.,0.,0,N_mdm(usharray,startOrderSeq)},
		{"start_rank_sequence",13,0,23,0,0,0.,0.,0,N_mdm(szarray,startRankSeq)},
		{"statistics_mode",8,2,5,0,kw_727},
		{"tensor_grid",8,0,15,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"variance_based_decomp",8,2,38,0,kw_728,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_730[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_731[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_732[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_733[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_734[3] = {
		{"adapted",8,2,1,1,kw_733,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_735[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_736[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_737[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_738[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_739[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_740[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_741[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_735,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_735,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_736,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_737,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_738,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_738,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_737,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_739,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_740,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_740,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_742[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_743[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_744[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_743,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_745[6] = {
		{"basis_type",8,3,2,0,kw_734},
		{"collocation_ratio",10,21,3,1,kw_741,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_742,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_744,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_744,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_746[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_747[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_746,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_748[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_749[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_750[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_751[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_750,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_752[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_753[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_752,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_754[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_753,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_753,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_755[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_756[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_757[2] = {
		{"dimension_adaptive",8,3,1,1,kw_756},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_758[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_759[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_760[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_761[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_762[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_763[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_762}
		},
	kw_764[2] = {
		{"compute",8,4,2,0,kw_763},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_765[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_766[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_767[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_768[2] = {
		{"active",8,0,1,1,0,0.,0.,0,N_mdm(type,statsMetricMode_ACTIVE_EXPANSION_STATS)},
		{"combined",8,0,1,1,0,0.,0.,0,N_mdm(type,statsMetricMode_COMBINED_EXPANSION_STATS)}
		},
	kw_769[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_770[38] = {
		{"allocation_control",8,1,6,0,kw_730},
		{"askey",8,0,9,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,23,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,7,0,kw_731},
		{"distribution",8,2,21,0,kw_732},
		{"expansion_order_sequence",13,6,8,1,kw_745,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_approx_points_file",11,3,25,0,kw_747,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_expansion_file",11,0,11,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"export_points_file",3,3,25,0,kw_747,0.,0.,-2,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,16,0,kw_748},
		{"fixed_seed",8,0,27,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,23,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,20,0,kw_749,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,24,0,kw_751,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"least_interpolation",0,6,8,1,kw_754,0.,0.,6,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"metric_scale",8,2,4,0,kw_755},
		{"model_pointer",11,0,28,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"normalized",8,0,10,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,8,1,kw_754,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,8,1,kw_754,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_757,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"probability_levels",14,1,18,0,kw_758,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,15,0,kw_759},
		{"quadrature_order_sequence",13,3,8,1,kw_760,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"reliability_levels",14,1,19,0,kw_761,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,17,0,kw_764,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,14,0,kw_765},
		{"sample_refinement",0,4,15,0,kw_759,0.,0.,-5},
		{"sample_type",8,2,13,0,kw_766},
		{"samples",1,0,12,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,12,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed_sequence",13,0,26,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"sparse_grid_level_sequence",13,5,8,1,kw_767,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"statistics_mode",8,2,5,0,kw_768},
		{"variance_based_decomp",8,2,22,0,kw_769,0.,0.,0,N_mdm(true,vbdFlag)},
		{"wiener",8,0,9,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_771[1] = {
		{"greedy",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_GREEDY_REFINEMENT)}
		},
	kw_772[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_773[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_774[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_775[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_774,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_776[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_777[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_778[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_779[3] = {
		{"dimension_adaptive",8,2,1,1,kw_778},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_780[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_781[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_780,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_782[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_783[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_784[2] = {
		{"dimension_adaptive",8,2,1,1,kw_783},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_785[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_786[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_787[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_788[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_789[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_790[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_789}
		},
	kw_791[2] = {
		{"compute",8,4,2,0,kw_790},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_792[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_793[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_794[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_795[2] = {
		{"active",8,0,1,1,0,0.,0.,0,N_mdm(type,statsMetricMode_ACTIVE_EXPANSION_STATS)},
		{"combined",8,0,1,1,0,0.,0.,0,N_mdm(type,statsMetricMode_COMBINED_EXPANSION_STATS)}
		},
	kw_796[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_797[35] = {
		{"allocation_control",8,1,6,0,kw_771},
		{"askey",8,0,9,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,22,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,7,0,kw_772},
		{"distribution",8,2,20,0,kw_773},
		{"export_approx_points_file",11,3,24,0,kw_775,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,24,0,kw_775,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,15,0,kw_776},
		{"fixed_seed",8,0,26,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,22,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,19,0,kw_777,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"h_refinement",8,3,1,0,kw_779,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"import_approx_points_file",11,4,23,0,kw_781,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"metric_scale",8,2,4,0,kw_782},
		{"model_pointer",11,0,27,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"p_refinement",8,2,1,0,kw_784,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,9,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"probability_levels",14,1,17,0,kw_785,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,14,0,kw_786},
		{"quadrature_order_sequence",13,3,8,1,kw_787,0.,0.,0,N_mdm(usharray,quadratureOrderSeq)},
		{"reliability_levels",14,1,18,0,kw_788,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,16,0,kw_791,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,13,0,kw_792},
		{"sample_refinement",0,4,14,0,kw_786,0.,0.,-5},
		{"sample_type",8,2,12,0,kw_793},
		{"samples",1,0,11,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,11,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed_sequence",13,0,25,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"sparse_grid_level_sequence",13,7,8,1,kw_794,0.,0.,0,N_mdm(usharray,sparseGridLevelSeq)},
		{"statistics_mode",8,2,5,0,kw_795},
		{"use_derivatives",8,0,10,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"variance_based_decomp",8,2,21,0,kw_796,0.,0.,0,N_mdm(true,vbdFlag)},
		{"wiener",8,0,9,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_798[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportSamplesFormat_TABULAR_IFACE_ID)}
		},
	kw_799[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_798,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportSamplesFormat_TABULAR_NONE)}
		},
	kw_800[5] = {
		{"best_conditioned",0x19,0,1,1,0,0.,0.,0,N_mdm(sizet,rCondBestThrottle)},
		{"common_groups",8,0,1,1,0,0.,0.,0,N_mdm(type,groupThrottleType_COMMON_ESTIMATOR_GROUPS)},
		{"group_size",0x19,0,1,1,0,0.,0.,0,N_mdm(ushint,groupSizeThrottle)},
		{"mfmc_groups",8,0,1,1,0,0.,0.,0,N_mdm(type,groupThrottleType_MFMC_ESTIMATOR_GROUPS)},
		{"rcond_tolerance",0x2a,0,1,1,0,0.,0.,0,N_mdm(Real,rCondTolThrottle)}
		},
	kw_801[1] = {
		{"independent",8,0,1,0,0,0.,0.,0,N_mdm(type,pilotGroupSampling_INDEPENDENT_PILOT)}
		},
	kw_802[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_803[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_804[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_805[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_806[2] = {
		{"distribution",8,2,2,0,kw_804},
		{"final_moments",8,3,1,0,kw_805}
		},
	kw_807[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_806,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_808[1] = {
		{"final_statistics",8,2,1,0,kw_807}
		},
	kw_809[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_810[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_811[2] = {
		{"distribution",8,2,2,0,kw_809},
		{"final_moments",8,3,1,0,kw_810}
		},
	kw_812[2] = {
		{"estimator_performance",8,0,1,1,0,0.,0.,0,N_mdm(utype,finalStatsType_ESTIMATOR_PERFORMANCE)},
		{"qoi_statistics",8,2,1,1,kw_811,0.,0.,0,N_mdm(utype,finalStatsType_QOI_STATISTICS)}
		},
	kw_813[3] = {
		{"factor_sequence",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,relaxFactorSequence)},
		{"fixed_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxFixedFactor)},
		{"recursive_factor",10,0,1,1,0,0.,0.,0,N_mdm(Real,relaxRecursiveFactor)}
		},
	kw_814[2] = {
		{"final_statistics",8,2,2,0,kw_812},
		{"relaxation",8,3,1,0,kw_813}
		},
	kw_815[4] = {
		{"offline_pilot",8,1,1,1,kw_808,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT)},
		{"offline_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_OFFLINE_PILOT_PROJECTION)},
		{"online_pilot",8,2,1,1,kw_814,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT)},
		{"online_projection",8,0,1,1,0,0.,0.,0,N_mdm(type,ensemblePilotSolnMode_ONLINE_PILOT_PROJECTION)}
		},
	kw_816[17] = {
		{"competed_local",8,0,4,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL_OPTPP)},
		{"convergence_tolerance",10,0,9,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"export_sample_sequence",8,3,8,0,kw_799,0.,0.,0,N_mdm(true,exportSampleSeqFlag)},
		{"fixed_seed",8,0,6,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"global_local",8,0,4,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_DIRECT_NPSOL_OPTPP)},
		{"group_throttle",8,5,1,0,kw_800},
		{"initial_samples",5,1,2,0,kw_801,0.,0.,5,N_mdm(szarray,pilotSamples)},
		{"max_function_evaluations",0x29,0,11,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,13,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"nip",8,0,4,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_OPTPP)},
		{"pilot_samples",13,1,2,0,kw_801,0.,0.,0,N_mdm(szarray,pilotSamples)},
		{"rng",8,2,12,0,kw_802},
		{"sample_type",8,2,7,0,kw_803},
		{"seed_sequence",13,0,5,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solution_mode",8,4,3,0,kw_815},
		{"sqp",8,0,4,0,0,0.,0.,0,N_mdm(utype,optSubProbSolver_SUBMETHOD_NPSOL)}
		},
	kw_817[1] = {
		{"estimator_rate",10,0,1,0,0,0.,0.,0,N_mdm(Real,multilevEstimatorRate)}
		},
	kw_818[2] = {
		{"estimator_variance",8,1,1,1,kw_817,0.,0.,0,N_mdm(type,multilevAllocControl_ESTIMATOR_VARIANCE)},
		{"rank_sampling",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_RANK_SAMPLING)}
		},
	kw_819[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_820[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_821[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_822[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_821,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_823[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_824[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_825[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_826[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_825,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_827[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_828[1] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)}
		},
	kw_829[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_830[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_831[1] = {
		{"l2_penalty",10,0,1,1,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)}
		},
	kw_832[2] = {
		{"ls",8,0,1,1,0,0.,0.,0,N_mdm(type,regressionType_FT_LS)},
		{"rls2",8,1,1,1,kw_831,0.,0.,0,N_mdm(type,regressionType_FT_RLS2)}
		},
	kw_833[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_834[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_835[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_834}
		},
	kw_836[2] = {
		{"compute",8,4,2,0,kw_835},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_837[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_838[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_839[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_840[49] = {
		{"adapt_order",8,0,17,0,0,0.,0.,0,N_mdm(true,adaptOrder)},
		{"adapt_rank",8,0,22,0,0,0.,0.,0,N_mdm(true,adaptRank)},
		{"allocation_control",8,2,2,0,kw_818},
		{"arithmetic_tolerance",10,0,7,0,0,0.,0.,0,N_mdm(Real,statsRoundingTol)},
		{"collocation_points_sequence",13,0,14,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"collocation_ratio",10,0,15,0,0,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,37,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,5,0,kw_819},
		{"distribution",8,2,35,0,kw_820},
		{"export_approx_points_file",11,3,39,0,kw_822,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,39,0,kw_822,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,30,0,kw_823},
		{"fixed_seed",8,0,41,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,37,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,34,0,kw_824,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,38,0,kw_826,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"kick_order",0x19,0,18,0,0,0.,0.,0,N_mdm(ushint,kickOrder)},
		{"kick_rank",0x19,0,23,0,0,0.,0.,0,N_mdm(sizet,kickRank)},
		{"max_cross_iterations",0x29,0,10,0,0,0.,0.,0,N_mdm(int,maxCrossIterations)},
		{"max_cv_order_candidates",0x29,0,20,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"max_cv_rank_candidates",0x29,0,25,0,0,0.,0.,0,N_mdm(sizet,maxCVRankCandidates)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"max_order",0x29,0,19,0,0,0.,0.,0,N_mdm(ushint,maxOrder)},
		{"max_rank",0x29,0,24,0,0,0.,0.,0,N_mdm(sizet,maxRank)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"metric_scale",8,2,4,0,kw_827},
		{"model_pointer",11,0,42,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"order_sequence",5,1,16,0,kw_828,0.,0.,17,N_mdm(usharray,startOrderSeq)},
		{"pilot_samples",5,0,14,0,0,0.,0.,-25,N_mdm(szarray,collocationPointsSeq)},
		{"probability_levels",14,1,32,0,kw_829,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,29,0,kw_830},
		{"rank_sequence",5,0,21,0,0,0.,0.,14,N_mdm(szarray,startRankSeq)},
		{"regression_type",8,2,8,0,kw_832},
		{"reliability_levels",14,1,33,0,kw_833,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,31,0,kw_836,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"response_scaling",8,0,12,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"rng",8,2,28,0,kw_837},
		{"rounding_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,solverRoundingTol)},
		{"sample_refinement",0,4,29,0,kw_830,0.,0.,-8},
		{"sample_type",8,2,27,0,kw_838},
		{"samples",1,0,26,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,26,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed_sequence",13,0,40,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"solver_tolerance",10,0,11,0,0,0.,0.,0,N_mdm(Real,solverTol)},
		{"start_order_sequence",13,1,16,0,kw_828,0.,0.,0,N_mdm(usharray,startOrderSeq)},
		{"start_rank_sequence",13,0,21,0,0,0.,0.,0,N_mdm(szarray,startRankSeq)},
		{"tensor_grid",8,0,13,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"variance_based_decomp",8,2,36,0,kw_839,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_841[1] = {
		{"estimator_rate",10,0,1,0,0,0.,0.,0,N_mdm(Real,multilevEstimatorRate)}
		},
	kw_842[2] = {
		{"estimator_variance",8,1,1,1,kw_841,0.,0.,0,N_mdm(type,multilevAllocControl_ESTIMATOR_VARIANCE)},
		{"rip_sampling",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevAllocControl_RIP_SAMPLING)}
		},
	kw_843[3] = {
		{"distinct",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"paired",0,0,1,1,0,0.,0.,-1,N_mdm(type,multilevDiscrepEmulation_DISTINCT_EMULATION)},
		{"recursive",8,0,1,1,0,0.,0.,0,N_mdm(type,multilevDiscrepEmulation_RECURSIVE_EMULATION)}
		},
	kw_844[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_845[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_846[3] = {
		{"adapted",8,2,1,1,kw_845,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_847[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_848[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_849[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_850[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_851[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_852[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_853[21] = {
		{"basis_pursuit",8,0,2,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,2,0,kw_847,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,2,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,2,0,kw_847,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"collocation_points_sequence",13,0,1,0,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"cross_validation",8,2,3,0,kw_848,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,2,0,kw_849,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,2,0,kw_850,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,2,0,kw_850,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,2,0,kw_849,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,2,0,kw_851,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,9,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,2,0,kw_852,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,2,0,kw_852,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"pilot_samples",5,0,1,0,0,0.,0.,-10,N_mdm(szarray,collocationPointsSeq)},
		{"ratio_order",10,0,4,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,8,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,8,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,7,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,6,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_854[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_855[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_856[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_855,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_857[6] = {
		{"basis_type",8,3,2,0,kw_846},
		{"collocation_ratio",10,21,3,1,kw_853,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples_sequence",13,2,3,1,kw_854,0.,0.,0,N_mdm(szarray,expansionSamplesSeq)},
		{"import_build_points_file",11,4,4,0,kw_856,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_856,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_858[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_859[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_858,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_860[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_861[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_862[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_863[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_862,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_864[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_865[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_864,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_866[6] = {
		{"collocation_points_sequence",13,0,1,1,0,0.,0.,0,N_mdm(szarray,collocationPointsSeq)},
		{"import_build_points_file",11,4,4,0,kw_865,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_865,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_867[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_868[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_869[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_870[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_871[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_872[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_871}
		},
	kw_873[2] = {
		{"compute",8,4,2,0,kw_872},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_874[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_875[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_876[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_877[34] = {
		{"allocation_control",8,2,2,0,kw_842},
		{"askey",8,0,7,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,21,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"discrepancy_emulation",8,3,5,0,kw_843},
		{"distribution",8,2,19,0,kw_844},
		{"expansion_order_sequence",13,6,6,1,kw_857,0.,0.,0,N_mdm(usharray,expansionOrderSeq)},
		{"export_approx_points_file",11,3,23,0,kw_859,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_expansion_file",11,0,9,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"export_points_file",3,3,23,0,kw_859,0.,0.,-2,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,14,0,kw_860},
		{"fixed_seed",8,0,25,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,21,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,18,0,kw_861,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,22,0,kw_863,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"least_interpolation",0,6,6,1,kw_866,0.,0.,6,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"metric_scale",8,2,4,0,kw_867},
		{"model_pointer",11,0,26,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"normalized",8,0,8,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,6,1,kw_866,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,6,1,kw_866,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"probability_levels",14,1,16,0,kw_868,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,13,0,kw_869},
		{"reliability_levels",14,1,17,0,kw_870,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,15,0,kw_873,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,12,0,kw_874},
		{"sample_refinement",0,4,13,0,kw_869,0.,0.,-4},
		{"sample_type",8,2,11,0,kw_875},
		{"samples",1,0,10,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,10,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed_sequence",13,0,24,0,0,0.,0.,0,N_mdm(szarray,randomSeedSeq)},
		{"variance_based_decomp",8,2,20,0,kw_876,0.,0.,0,N_mdm(true,vbdFlag)},
		{"wiener",8,0,7,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_878[9] = {
		{"convergence_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,6,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"min_boxsize_limit",10,0,2,0,0,0.,0.,0,N_mdm(Real,minBoxSize)},
		{"model_pointer",11,0,8,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,7,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"solution_accuracy",2,0,1,0,0,0.,0.,1,N_mdm(Real,solnTarget)},
		{"solution_target",10,0,1,0,0,0.,0.,0,N_mdm(Real,solnTarget)},
		{"volume_boxsize_limit",10,0,3,0,0,0.,0.,0,N_mdm(Real,volBoxSize)}
		},
	kw_879[15] = {
		{"absolute_conv_tol",10,0,2,0,0,0.,0.,0,N_mdm(Real,absConvTol)},
		{"convergence_tolerance",10,0,10,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"covariance",9,0,8,0,0,0.,0.,0,N_mdm(int,covarianceType)},
		{"false_conv_tol",10,0,6,0,0,0.,0.,0,N_mdm(Real,falseConvTol)},
		{"function_precision",10,0,1,0,0,0.,0.,0,N_mdm(Real,functionPrecision)},
		{"initial_trust_radius",10,0,7,0,0,0.,0.,0,N_mdm(Real,initTRRadius)},
		{"max_function_evaluations",0x29,0,13,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,11,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,15,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"regression_diagnostics",8,0,9,0,0,0.,0.,0,N_mdm(true,regressDiag)},
		{"scaling",8,0,14,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"singular_conv_tol",10,0,4,0,0,0.,0.,0,N_mdm(Real,singConvTol)},
		{"singular_radius",10,0,5,0,0,0.,0.,0,N_mdm(Real,singRadius)},
		{"speculative",8,0,12,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"x_conv_tol",10,0,3,0,0,0.,0.,0,N_mdm(Real,xConvTol)}
		},
	kw_880[5] = {
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,5,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,methodScaling)}
		},
	kw_881[10] = {
		{"constraint_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"function_precision",10,0,2,0,0,0.,0.,0,N_mdm(Real,functionPrecision)},
		{"linesearch_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,lineSearchTolerance)},
		{"max_function_evaluations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,9,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,7,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"verify_level",9,0,1,0,0,0.,0.,0,N_mdm(int,verifyLevel)}
		},
	kw_882[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_883[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_884[2] = {
		{"global",8,0,1,1,0,0.,0.,0,N_mdm(lit,lipschitzType_global)},
		{"local",8,0,1,1,0,0.,0.,0,N_mdm(lit,lipschitzType_local)}
		},
	kw_885[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_886[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_887[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_886}
		},
	kw_888[2] = {
		{"compute",8,3,2,0,kw_887},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_889[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_890[11] = {
		{"build_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"distribution",8,2,8,0,kw_882},
		{"gen_reliability_levels",14,1,7,0,kw_883,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"lipschitz",8,2,3,0,kw_884},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,6,0,kw_885,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"response_levels",14,2,5,0,kw_888,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,9,0,kw_889},
		{"samples",1,0,1,1,0,0.,0.,-8,N_mdm(int,buildSamples)},
		{"samples_on_emulator",9,0,4,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_891[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_892[2] = {
		{"advancements",9,0,1,0,0,0.,0.,0,N_mdm(ushint,adaptedBasisAdvancements)},
		{"soft_convergence_limit",9,0,2,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)}
		},
	kw_893[3] = {
		{"adapted",8,2,1,1,kw_892,0.,0.,0,N_mdm(type,expansionBasisType_ADAPTED_BASIS_EXPANDING_FRONT)},
		{"tensor_product",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TENSOR_PRODUCT_BASIS)},
		{"total_order",8,0,1,1,0,0.,0.,0,N_mdm(type,expansionBasisType_TOTAL_ORDER_BASIS)}
		},
	kw_894[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_895[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_896[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_897[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_898[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_899[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_900[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_894,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_894,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_895,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_896,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_897,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_897,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_896,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_898,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_899,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_899,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_901[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_902[2] = {
		{"max_cv_order_candidates",0x29,0,2,0,0,0.,0.,0,N_mdm(ushint,maxCVOrderCandidates)},
		{"noise_only",8,0,1,0,0,0.,0.,0,N_mdm(true,crossValidNoiseOnly)}
		},
	kw_903[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_904[2] = {
		{"l2_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Real,regressionL2Penalty)},
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_905[2] = {
		{"equality_constrained",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_EQ_CON_LS)},
		{"svd",8,0,1,0,0,0.,0.,0,N_mdm(type,lsRegressionType_SVD_LS)}
		},
	kw_906[1] = {
		{"noise_tolerance",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,regressionNoiseTol)}
		},
	kw_907[19] = {
		{"basis_pursuit",8,0,1,0,0,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"basis_pursuit_denoising",8,1,1,0,kw_901,0.,0.,0,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"bp",0,0,1,0,0,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT)},
		{"bpdn",0,1,1,0,kw_901,0.,0.,-2,N_mdm(type,regressionType_BASIS_PURSUIT_DENOISING)},
		{"cross_validation",8,2,2,0,kw_902,0.,0.,0,N_mdm(true,crossValidation)},
		{"lars",0,1,1,0,kw_903,0.,0.,3,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"lasso",0,2,1,0,kw_904,0.,0.,1,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_absolute_shrinkage",8,2,1,0,kw_904,0.,0.,0,N_mdm(type,regressionType_LASSO_REGRESSION)},
		{"least_angle_regression",8,1,1,0,kw_903,0.,0.,0,N_mdm(type,regressionType_LEAST_ANGLE_REGRESSION)},
		{"least_squares",8,2,1,0,kw_905,0.,0.,0,N_mdm(type,regressionType_DEFAULT_LEAST_SQ_REGRESSION)},
		{"max_solver_iterations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxSolverIterations)},
		{"omp",0,1,1,0,kw_906,0.,0.,1,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"orthogonal_matching_pursuit",8,1,1,0,kw_906,0.,0.,0,N_mdm(type,regressionType_ORTHOG_MATCH_PURSUIT)},
		{"ratio_order",10,0,3,0,0,0.,0.,0,N_mdm(Realp,collocRatioTermsOrder)},
		{"response_scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,respScalingFlag)},
		{"reuse_points",8,0,7,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,7,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mdm(true,tensorGridFlag)},
		{"use_derivatives",8,0,5,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)}
		},
	kw_908[2] = {
		{"reuse_points",8,0,1,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,1,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)}
		},
	kw_909[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_910[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_909,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_911[7] = {
		{"basis_type",8,3,2,0,kw_893},
		{"collocation_points",9,19,3,1,kw_900,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"collocation_ratio",10,19,3,1,kw_907,0.,0.,0,N_mdm(Realp,collocationRatio)},
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"expansion_samples",9,2,3,1,kw_908,0.,0.,0,N_mdm(sizet,expansionSamples)},
		{"import_build_points_file",11,4,4,0,kw_910,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_910,0.,0.,-1,N_mdm(str,importBuildPtsFile)}
		},
	kw_912[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_913[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_912,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_914[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_915[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_916[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_917[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_916,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_918[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_919[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importBuildActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_918,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_920[6] = {
		{"collocation_points",9,0,1,1,0,0.,0.,0,N_mdm(sizet,collocationPoints)},
		{"import_build_points_file",11,4,4,0,kw_919,0.,0.,0,N_mdm(str,importBuildPtsFile)},
		{"import_points_file",3,4,4,0,kw_919,0.,0.,-1,N_mdm(str,importBuildPtsFile)},
		{"reuse_points",8,0,3,0,0,0.,0.,0,N_mdm(lit,pointReuse_all)},
		{"reuse_samples",0,0,3,0,0,0.,0.,-1,N_mdm(lit,pointReuse_all)},
		{"tensor_grid",13,0,2,0,0,0.,0.,0,N_mdm(usharray,tensorGridOrder)}
		},
	kw_921[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_922[3] = {
		{"decay",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_DECAY)},
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_923[2] = {
		{"dimension_adaptive",8,3,1,1,kw_922},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_924[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_925[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_926[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_927[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_928[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_929[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_928}
		},
	kw_930[2] = {
		{"compute",8,4,2,0,kw_929},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_931[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_932[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_933[5] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,3,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,2,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_934[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_935[37] = {
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"cubature_integrand",9,0,5,1,0,0.,0.,0,N_mdm(ushint,cubIntOrder)},
		{"diagonal_covariance",8,0,20,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"distribution",8,2,18,0,kw_891},
		{"expansion_order",9,7,5,1,kw_911,0.,0.,0,N_mdm(ushint,expansionOrder)},
		{"export_approx_points_file",11,3,22,0,kw_913,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_expansion_file",11,0,8,0,0,0.,0.,0,N_mdm(str,exportExpansionFile)},
		{"export_points_file",3,3,22,0,kw_913,0.,0.,-2,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,13,0,kw_914},
		{"fixed_seed",8,0,24,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,20,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,17,0,kw_915,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,21,0,kw_917,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"import_expansion_file",11,0,5,1,0,0.,0.,0,N_mdm(str,importExpansionFile)},
		{"least_interpolation",0,6,5,1,kw_920,0.,0.,6,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"metric_scale",8,2,4,0,kw_921},
		{"model_pointer",11,0,25,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"normalized",8,0,7,0,0,0.,0.,0,N_mdm(true,normalizedCoeffs)},
		{"oli",0,6,5,1,kw_920,0.,0.,1,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"orthogonal_least_interpolation",8,6,5,1,kw_920,0.,0.,0,N_mdm(type,regressionType_ORTHOG_LEAST_INTERPOLATION)},
		{"p_refinement",8,2,1,0,kw_923,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"probability_levels",14,1,15,0,kw_924,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,12,0,kw_925},
		{"quadrature_order",9,3,5,1,kw_926,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"reliability_levels",14,1,16,0,kw_927,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,14,0,kw_930,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,11,0,kw_931},
		{"sample_refinement",0,4,12,0,kw_925,0.,0.,-5},
		{"sample_type",8,2,10,0,kw_932},
		{"samples",1,0,9,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,9,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,23,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"sparse_grid_level",9,5,5,1,kw_933,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"variance_based_decomp",8,2,19,0,kw_934,0.,0.,0,N_mdm(true,vbdFlag)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_936[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_937[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_938[2] = {
		{"global",8,0,1,1,0,0.,0.,0,N_mdm(lit,lipschitzType_global)},
		{"local",8,0,1,1,0,0.,0.,0,N_mdm(lit,lipschitzType_local)}
		},
	kw_939[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_940[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_941[3] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"system",8,2,2,0,kw_940}
		},
	kw_942[2] = {
		{"compute",8,3,2,0,kw_941},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_943[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_944[11] = {
		{"build_samples",9,0,1,1,0,0.,0.,0,N_mdm(int,buildSamples)},
		{"distribution",8,2,8,0,kw_936},
		{"gen_reliability_levels",14,1,7,0,kw_937,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"lipschitz",8,2,3,0,kw_938},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,6,0,kw_939,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"response_levels",14,2,5,0,kw_942,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,9,0,kw_943},
		{"samples",1,0,1,1,0,0.,0.,-8,N_mdm(int,buildSamples)},
		{"samples_on_emulator",9,0,4,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_945[2] = {
		{"candidate_designs",0x19,0,1,0,0,0.,0.,0,N_mdm(sizet,numCandidateDesigns)},
		{"leja_oversample_ratio",10,0,1,0,0,0.,0.,0,N_mdm(Real,collocationRatio)}
		},
	kw_946[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_947[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_948[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_949[1] = {
		{"percent_variance_explained",10,0,1,0,0,0.,0.,0,N_mdm(Real,percentVarianceExplained)}
		},
	kw_950[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_951[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_952[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_953[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_952}
		},
	kw_954[2] = {
		{"compute",8,4,2,0,kw_953},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_955[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_956[2] = {
		{"joe_kuo",8,0,1,1,0,0.,0.,0,N_mdm(true,joe_kuo)},
		{"sobol_order_2",8,0,1,1,0,0.,0.,0,N_mdm(true,sobol_order_2)}
		},
	kw_957[3] = {
		{"file",11,0,1,1,0,0.,0.,0,N_mdm(str,generatingMatricesFileName)},
		{"inline",13,0,1,1,0,0.,0.,0,N_mdm(ivec,generatingMatrices)},
		{"predefined",8,2,1,1,kw_956}
		},
	kw_958[2] = {
		{"least_significant_bit_first",8,0,1,1,0,0.,0.,0,N_mdm(true,leastSignificantBitFirst)},
		{"most_significant_bit_first",8,0,1,1,0,0.,0.,0,N_mdm(true,mostSignificantBitFirst)}
		},
	kw_959[2] = {
		{"gray_code",8,0,1,1,0,0.,0.,0,N_mdm(true,grayCodeOrdering)},
		{"natural",8,0,1,1,0,0.,0.,0,N_mdm(true,naturalOrdering)}
		},
	kw_960[8] = {
		{"generating_matrices",8,3,7,0,kw_957},
		{"integer_format",8,2,3,0,kw_958},
		{"m_max",0x29,0,4,0,0,0.,0.,0,N_mdm(int,log2MaxPoints)},
		{"no_digital_shift",8,0,1,0,0,0.,0.,0,N_mdm(true,noDigitalShiftFlag)},
		{"no_scrambling",8,0,2,0,0,0.,0.,0,N_mdm(true,noScramblingFlag)},
		{"ordering",8,2,8,0,kw_959},
		{"t_max",0x29,0,5,0,0,0.,0.,0,N_mdm(int,numberOfBits)},
		{"t_scramble",0x29,0,6,0,0,0.,0.,0,N_mdm(int,scrambleSize)}
		},
	kw_961[2] = {
		{"cools_kuo_nuyens",8,0,1,1,0,0.,0.,0,N_mdm(true,cools_kuo_nuyens)},
		{"kuo",8,0,1,1,0,0.,0.,0,N_mdm(true,kuo)}
		},
	kw_962[3] = {
		{"file",11,0,1,1,0,0.,0.,0,N_mdm(str,generatingVectorFileName)},
		{"inline",13,0,1,1,0,0.,0.,0,N_mdm(ivec,generatingVector)},
		{"predefined",8,2,1,1,kw_961}
		},
	kw_963[2] = {
		{"natural",8,0,1,1,0,0.,0.,0,N_mdm(true,naturalOrdering)},
		{"radical_inverse",8,0,1,1,0,0.,0.,0,N_mdm(true,radicalInverseOrdering)}
		},
	kw_964[4] = {
		{"generating_vector",8,3,3,0,kw_962},
		{"m_max",0x29,0,2,0,0,0.,0.,0,N_mdm(int,log2MaxPoints)},
		{"no_random_shift",8,0,1,0,0,0.,0.,0,N_mdm(true,noRandomShiftFlag)},
		{"ordering",8,2,4,0,kw_963}
		},
	kw_965[3] = {
		{"digital_net",8,8,2,0,kw_960,0.,0.,0,N_mdm(true,digitalNetFlag)},
		{"rank_1_lattice",8,4,1,0,kw_964,0.,0.,0,N_mdm(true,rank1LatticeFlag)},
		{"sobol_sequence",0,8,2,0,kw_960,0.,0.,-2,N_mdm(true,digitalNetFlag)}
		},
	kw_966[6] = {
		{"incremental_lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"incremental_random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)},
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"low_discrepancy",8,3,1,1,kw_965,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LOW_DISCREPANCY_SAMPLING)},
		{"qmc",0,3,1,1,kw_965,0.,0.,-1,N_mdm(utype,sampleType_SUBMETHOD_LOW_DISCREPANCY_SAMPLING)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_967[2] = {
		{"confidence_level",10,0,2,0,0,0.,0.,0,N_mdm(Real01,tiConfidenceLevel)},
		{"coverage",10,0,1,0,0,0.,0.,0,N_mdm(Real01,tiCoverage)}
		},
	kw_968[1] = {
		{"num_bins",9,0,1,0,0,0.,0.,0,N_mdm(int,vbdViaSamplingNumBins)}
		},
	kw_969[2] = {
		{"binned",8,1,1,1,kw_968,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_BINNED)},
		{"pick_and_freeze",8,0,1,1,0,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod_VBD_PICK_AND_FREEZE)}
		},
	kw_970[2] = {
		{"drop_tolerance",10,0,1,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"vbd_sampling_method",8,2,2,0,kw_969,0.,0.,0,N_mdm(utype,vbdViaSamplingMethod)}
		},
	kw_971[5] = {
		{"confidence_level",10,0,2,0,0,0.,0.,0,N_mdm(Real,wilksConfidenceLevel)},
		{"one_sided_lower",8,0,3,0,0,0.,0.,0,N_mdm(type,wilksSidedInterval_ONE_SIDED_LOWER)},
		{"one_sided_upper",8,0,4,0,0,0.,0.,0,N_mdm(type,wilksSidedInterval_ONE_SIDED_UPPER)},
		{"order",9,0,1,0,0,0.,0.,0,N_mdm(ushint,wilksOrder)},
		{"two_sided",8,0,5,0,0,0.,0.,0,N_mdm(type,wilksSidedInterval_TWO_SIDED)}
		},
	kw_972[21] = {
		{"backfill",8,0,8,0,0,0.,0.,0,N_mdm(true,backfillFlag)},
		{"d_optimal",8,2,6,0,kw_945,0.,0.,0,N_mdm(true,dOptimal)},
		{"distribution",8,2,18,0,kw_946},
		{"final_moments",8,3,13,0,kw_947},
		{"fixed_seed",8,0,3,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"gen_reliability_levels",14,1,17,0,kw_948,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"initial_samples",1,0,1,0,0,0.,0.,9,N_mdm(int,numSamples)},
		{"model_pointer",11,0,20,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"principal_components",8,1,9,0,kw_949,0.,0.,0,N_mdm(true,pcaFlag)},
		{"probability_levels",14,1,15,0,kw_950,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"refinement_samples",13,0,5,0,0,0.,0.,0,N_mdm(ivec,refineSamples)},
		{"reliability_levels",14,1,16,0,kw_951,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,14,0,kw_954,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,19,0,kw_955},
		{"sample_type",8,6,4,0,kw_966},
		{"samples",9,0,1,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"seed",0x19,0,2,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"std_regression_coeffs",8,0,11,0,0,0.,0.,0,N_mdm(true,stdRegressionCoeffs)},
		{"tolerance_intervals",8,2,12,0,kw_967,0.,0.,0,N_mdm(true,toleranceIntervalsFlag)},
		{"variance_based_decomp",8,2,7,0,kw_970,0.,0.,0,N_mdm(true,vbdFlag)},
		{"wilks",8,5,10,0,kw_971,0.,0.,0,N_mdm(true,wilksFlag)}
		},
	kw_973[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_974[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_975[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_974,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_976[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_977[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_978[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_979[3] = {
		{"dimension_adaptive",8,2,1,1,kw_978},
		{"local_adaptive",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_LOCAL_ADAPTIVE_CONTROL)},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_980[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_981[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_980,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_982[2] = {
		{"absolute",8,0,1,1,0,0.,0.,0,N_mdm(false,relativeConvMetric)},
		{"relative",8,0,1,1,0,0.,0.,0,N_mdm(true,relativeConvMetric)}
		},
	kw_983[2] = {
		{"generalized",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_GENERALIZED)},
		{"sobol",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_DIMENSION_ADAPTIVE_CONTROL_SOBOL)}
		},
	kw_984[2] = {
		{"dimension_adaptive",8,2,1,1,kw_983},
		{"uniform",8,0,1,1,0,0.,0.,0,N_mdm(type,refinementControl_UNIFORM_CONTROL)}
		},
	kw_985[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_986[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_987[3] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"non_nested",8,0,2,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)}
		},
	kw_988[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_989[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_990[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_989}
		},
	kw_991[2] = {
		{"compute",8,4,2,0,kw_990},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_992[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_993[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_994[7] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)},
		{"hierarchical",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_HIERARCHICAL_INTERPOLANT)},
		{"nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NESTED)},
		{"nodal",8,0,2,0,0,0.,0.,0,N_mdm(type,expansionBasisType_NODAL_INTERPOLANT)},
		{"non_nested",8,0,4,0,0,0.,0.,0,N_mdm(type,nestingOverride_NON_NESTED)},
		{"restricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_RESTRICTED)},
		{"unrestricted",8,0,3,0,0,0.,0.,0,N_mdm(type,growthOverride_UNRESTRICTED)}
		},
	kw_995[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_996[32] = {
		{"askey",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_ASKEY_U)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"diagonal_covariance",8,0,19,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"distribution",8,2,17,0,kw_973},
		{"export_approx_points_file",11,3,21,0,kw_975,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,21,0,kw_975,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,12,0,kw_976},
		{"fixed_seed",8,0,23,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,19,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,16,0,kw_977,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"h_refinement",8,3,1,0,kw_979,0.,0.,0,N_mdm(type,refinementType_H_REFINEMENT)},
		{"import_approx_points_file",11,4,20,0,kw_981,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"max_refinement_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxRefineIterations)},
		{"metric_scale",8,2,4,0,kw_982},
		{"model_pointer",11,0,24,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"p_refinement",8,2,1,0,kw_984,0.,0.,0,N_mdm(type,refinementType_P_REFINEMENT)},
		{"piecewise",8,0,6,0,0,0.,0.,0,NIDRProblemDescDB::method_piecewise},
		{"probability_levels",14,1,14,0,kw_985,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,11,0,kw_986},
		{"quadrature_order",9,3,5,1,kw_987,0.,0.,0,N_mdm(ushint,quadratureOrder)},
		{"reliability_levels",14,1,15,0,kw_988,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,13,0,kw_991,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,10,0,kw_992},
		{"sample_refinement",0,4,11,0,kw_986,0.,0.,-5},
		{"sample_type",8,2,9,0,kw_993},
		{"samples",1,0,8,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,8,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,22,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"sparse_grid_level",9,7,5,1,kw_994,0.,0.,0,N_mdm(ushint,sparseGridLevel)},
		{"use_derivatives",8,0,7,0,0,0.,0.,0,N_mdm(true,methodUseDerivsFlag)},
		{"variance_based_decomp",8,2,18,0,kw_995,0.,0.,0,N_mdm(true,vbdFlag)},
		{"wiener",8,0,6,0,0,0.,0.,0,N_mdm(type,expansionType_STD_NORMAL_U)}
		},
	kw_997[5] = {
		{"convergence_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_iterations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"misc_options",15,0,1,0,0,0.,0.,0,N_mdm(strL,miscOptions)},
		{"model_pointer",11,0,5,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,methodScaling)}
		},
	kw_998[6] = {
		{"contract_threshold",10,0,3,0,0,0.,0.,0,N_mdm(Real,trustRegionContractTrigger)},
		{"contraction_factor",10,0,5,0,0,0.,0.,0,N_mdm(Real,trustRegionContract)},
		{"expand_threshold",10,0,4,0,0,0.,0.,0,N_mdm(Real,trustRegionExpandTrigger)},
		{"expansion_factor",10,0,6,0,0,0.,0.,0,N_mdm(Real,trustRegionExpand)},
		{"initial_size",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,trustRegionInitSize)},
		{"minimum_size",10,0,2,0,0,0.,0.,0,N_mdm(Real,trustRegionMinSize)}
		},
	kw_999[5] = {
		{"max_function_evaluations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,5,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,4,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"trust_region",8,6,1,0,kw_998,0.,0.,0,0,0,NIDRProblemDescDB::method_tr_final}
		},
	kw_1000[10] = {
		{"constraint_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"function_precision",10,0,2,0,0,0.,0.,0,N_mdm(Real,functionPrecision)},
		{"linesearch_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,lineSearchTolerance)},
		{"max_function_evaluations",0x29,0,8,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,10,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,9,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,7,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"verify_level",9,0,1,0,0,0.,0.,0,N_mdm(int,verifyLevel)}
		},
	kw_1001[8] = {
		{"convergence_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"gradient_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,gradientTolerance)},
		{"max_function_evaluations",0x29,0,6,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"max_step",10,0,1,0,0,0.,0.,0,N_mdm(Real,maxStep)},
		{"model_pointer",11,0,8,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,7,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"speculative",8,0,5,0,0,0.,0.,0,N_mdm(true,speculativeFlag)}
		},
	kw_1002[3] = {
		{"argaez_tapia",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_ArgaezTapia)},
		{"el_bakry",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_NormFmu)},
		{"van_shanno",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_VanShanno)}
		},
	kw_1003[4] = {
		{"gradient_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_gradient_based_line_search)},
		{"tr_pds",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_tr_pds)},
		{"trust_region",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_trust_region)},
		{"value_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_value_based_line_search)}
		},
	kw_1004[12] = {
		{"centering_parameter",10,0,4,0,0,0.,0.,0,N_mdm(Real,centeringParam)},
		{"convergence_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"gradient_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,gradientTolerance)},
		{"max_function_evaluations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"max_step",10,0,5,0,0,0.,0.,0,N_mdm(Real,maxStep)},
		{"merit_function",8,3,2,0,kw_1002},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,11,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"search_method",8,4,1,0,kw_1003},
		{"speculative",8,0,9,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"steplength_to_boundary",10,0,3,0,0,0.,0.,0,N_mdm(Real,stepLenToBoundary)}
		},
	kw_1005[3] = {
		{"argaez_tapia",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_ArgaezTapia)},
		{"el_bakry",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_NormFmu)},
		{"van_shanno",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_VanShanno)}
		},
	kw_1006[4] = {
		{"gradient_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_gradient_based_line_search)},
		{"tr_pds",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_tr_pds)},
		{"trust_region",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_trust_region)},
		{"value_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_value_based_line_search)}
		},
	kw_1007[12] = {
		{"centering_parameter",10,0,4,0,0,0.,0.,0,N_mdm(Real,centeringParam)},
		{"convergence_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"gradient_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,gradientTolerance)},
		{"max_function_evaluations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"max_step",10,0,5,0,0,0.,0.,0,N_mdm(Real,maxStep)},
		{"merit_function",8,3,2,0,kw_1005},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,11,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"search_method",8,4,1,0,kw_1006},
		{"speculative",8,0,9,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"steplength_to_boundary",10,0,3,0,0,0.,0.,0,N_mdm(Real,stepLenToBoundary)}
		},
	kw_1008[3] = {
		{"argaez_tapia",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_ArgaezTapia)},
		{"el_bakry",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_NormFmu)},
		{"van_shanno",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_VanShanno)}
		},
	kw_1009[4] = {
		{"gradient_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_gradient_based_line_search)},
		{"tr_pds",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_tr_pds)},
		{"trust_region",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_trust_region)},
		{"value_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_value_based_line_search)}
		},
	kw_1010[12] = {
		{"centering_parameter",10,0,4,0,0,0.,0.,0,N_mdm(Real,centeringParam)},
		{"convergence_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"gradient_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,gradientTolerance)},
		{"max_function_evaluations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"max_step",10,0,5,0,0,0.,0.,0,N_mdm(Real,maxStep)},
		{"merit_function",8,3,2,0,kw_1008},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,11,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"search_method",8,4,1,0,kw_1009},
		{"speculative",8,0,9,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"steplength_to_boundary",10,0,3,0,0,0.,0.,0,N_mdm(Real,stepLenToBoundary)}
		},
	kw_1011[6] = {
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_function_evaluations",0x29,0,4,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,6,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"search_scheme_size",9,0,1,0,0,0.,0.,0,N_mdm(int,searchSchemeSize)}
		},
	kw_1012[3] = {
		{"argaez_tapia",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_ArgaezTapia)},
		{"el_bakry",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_NormFmu)},
		{"van_shanno",8,0,1,1,0,0.,0.,0,N_mdm(type,meritFn_VanShanno)}
		},
	kw_1013[4] = {
		{"gradient_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_gradient_based_line_search)},
		{"tr_pds",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_tr_pds)},
		{"trust_region",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_trust_region)},
		{"value_based_line_search",8,0,1,1,0,0.,0.,0,N_mdm(lit,searchMethod_value_based_line_search)}
		},
	kw_1014[12] = {
		{"centering_parameter",10,0,4,0,0,0.,0.,0,N_mdm(Real,centeringParam)},
		{"convergence_tolerance",10,0,8,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"gradient_tolerance",10,0,6,0,0,0.,0.,0,N_mdm(Real,gradientTolerance)},
		{"max_function_evaluations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,7,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"max_step",10,0,5,0,0,0.,0.,0,N_mdm(Real,maxStep)},
		{"merit_function",8,3,2,0,kw_1012},
		{"model_pointer",11,0,12,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,11,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"search_method",8,4,1,0,kw_1013},
		{"speculative",8,0,9,0,0,0.,0.,0,N_mdm(true,speculativeFlag)},
		{"steplength_to_boundary",10,0,3,0,0,0.,0.,0,N_mdm(Real,stepLenToBoundary)}
		},
	kw_1015[5] = {
		{"debug",8,0,1,1,0,0.,0.,0,N_mdm(type,methodOutput_DEBUG_OUTPUT)},
		{"normal",8,0,1,1,0,0.,0.,0,N_mdm(type,methodOutput_NORMAL_OUTPUT)},
		{"quiet",8,0,1,1,0,0.,0.,0,N_mdm(type,methodOutput_QUIET_OUTPUT)},
		{"silent",8,0,1,1,0,0.,0.,0,N_mdm(type,methodOutput_SILENT_OUTPUT)},
		{"verbose",8,0,1,1,0,0.,0.,0,N_mdm(type,methodOutput_VERBOSE_OUTPUT)}
		},
	kw_1016[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_mdm(type,iteratorScheduling_PEER_SCHEDULING)}
		},
	kw_1017[2] = {
		{"model_pointer",11,0,1,0,0,0.,0.,0,N_mdm(str,subModelPointer)},
		{"opt_model_pointer",3,0,1,0,0,0.,0.,-1,N_mdm(str,subModelPointer)}
		},
	kw_1018[1] = {
		{"seed",9,0,1,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_1019[10] = {
		{"iterator_scheduling",8,2,5,0,kw_1016},
		{"iterator_servers",0x19,0,4,0,0,0.,0.,0,N_mdm(int,iteratorServers)},
		{"method_name",11,2,1,1,kw_1017,0.,0.,0,N_mdm(str,subMethodName)},
		{"method_pointer",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodPointer)},
		{"multi_objective_weight_sets",6,0,3,0,0,0.,0.,5,N_mdm(RealDL,concurrentParameterSets)},
		{"opt_method_name",3,2,1,1,kw_1017,0.,0.,-3,N_mdm(str,subMethodName)},
		{"opt_method_pointer",3,0,1,1,0,0.,0.,-3,N_mdm(str,subMethodPointer)},
		{"processors_per_iterator",0x19,0,6,0,0,0.,0.,0,N_mdm(int,procsPerIterator)},
		{"random_weight_sets",9,1,2,0,kw_1018,0.,0.,0,N_mdm(int,concurrentRandomJobs)},
		{"weight_sets",14,0,3,0,0,0.,0.,0,N_mdm(RealDL,concurrentParameterSets)}
		},
	kw_1020[4] = {
		{"model_pointer",11,0,4,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"partitions",13,0,1,0,0,0.,0.,0,N_mdm(usharray,varPartitions)},
		{"samples",9,0,2,0,0,0.,0.,0,N_mdm(int,numSamples)},
		{"seed",0x19,0,3,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_1021[7] = {
		{"converge_order",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_CONVERGE_ORDER)},
		{"converge_qoi",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_CONVERGE_QOI)},
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"estimate_order",8,0,1,1,0,0.,0.,0,N_mdm(utype,subMethod_SUBMETHOD_ESTIMATE_ORDER)},
		{"max_iterations",0x29,0,4,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,5,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"refinement_rate",10,0,2,0,0,0.,0.,0,N_mdm(Real,refinementRate)}
		},
	kw_1022[7] = {
		{"constraint_tolerance",10,0,4,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"gradient_tolerance",10,0,3,0,0,0.,0.,0,N_mdm(Real,gradientTolerance)},
		{"max_iterations",0x29,0,1,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,7,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"options_file",11,0,5,0,0,0.,0.,0,N_mdm(str,advancedOptionsFilename)},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"variable_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,threshStepLength)}
		},
	kw_1023[6] = {
		{"contract_threshold",10,0,3,0,0,0.,0.,0,N_mdm(Real,trustRegionContractTrigger)},
		{"contraction_factor",10,0,5,0,0,0.,0.,0,N_mdm(Real,trustRegionContract)},
		{"expand_threshold",10,0,4,0,0,0.,0.,0,N_mdm(Real,trustRegionExpandTrigger)},
		{"expansion_factor",10,0,6,0,0,0.,0.,0,N_mdm(Real,trustRegionExpand)},
		{"initial_size",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,trustRegionInitSize)},
		{"minimum_size",10,0,2,0,0,0.,0.,0,N_mdm(Real,trustRegionMinSize)}
		},
	kw_1024[6] = {
		{"max_function_evaluations",0x29,0,4,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,6,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"scaling",8,0,5,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,1,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"trust_region",8,6,2,0,kw_1023,0.,0.,0,0,0,NIDRProblemDescDB::method_tr_final}
		},
	kw_1025[2] = {
		{"num_generations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,numGenerations)},
		{"percent_change",10,0,1,0,0,0.,0.,0,N_mdm(Realz,convergenceTolerance)}
		},
	kw_1026[2] = {
		{"num_generations",0x29,0,2,0,0,0.,0.,0,N_mdm(sizet,numGenerations)},
		{"percent_change",10,0,1,0,0,0.,0.,0,N_mdm(Realz,convergenceTolerance)}
		},
	kw_1027[2] = {
		{"average_fitness_tracker",8,2,1,1,kw_1025,0.,0.,0,N_mdm(lit,convergenceType_average_fitness_tracker)},
		{"best_fitness_tracker",8,2,1,1,kw_1026,0.,0.,0,N_mdm(lit,convergenceType_best_fitness_tracker)}
		},
	kw_1028[2] = {
		{"num_offspring",0x19,0,2,0,0,0.,0.,0,N_mdm(sizet,numOffspring)},
		{"num_parents",0x19,0,1,0,0,0.,0.,0,N_mdm(sizet,numParents)}
		},
	kw_1029[5] = {
		{"crossover_rate",10,0,2,0,0,0.,0.,0,N_mdm(litz,TYPE_DATA_crossoverType_null_crossover)},
		{"multi_point_binary",9,0,1,1,0,0.,0.,0,N_mdm(ilit2p,TYPE_DATA_crossoverType_multi_point_binary)},
		{"multi_point_parameterized_binary",9,0,1,1,0,0.,0.,0,N_mdm(ilit2p,TYPE_DATA_crossoverType_multi_point_parameterized_binary)},
		{"multi_point_real",9,0,1,1,0,0.,0.,0,N_mdm(ilit2p,TYPE_DATA_crossoverType_multi_point_real)},
		{"shuffle_random",8,2,1,1,kw_1028,0.,0.,0,N_mdm(litc,TYPE_DATA_crossoverType_shuffle_random)}
		},
	kw_1030[2] = {
		{"constraint_penalty",10,0,2,0,0,0.,0.,0,N_mdm(Realp,constraintTolerance)},
		{"merit_function",8,0,1,1,0,0.,0.,0,N_mdm(lit,fitnessType_merit_function)}
		},
	kw_1031[3] = {
		{"flat_file",11,0,1,1,0,0.,0.,0,N_mdm(slit2,TYPE_DATA_initializationType_flat_file)},
		{"simple_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,initializationType_random)},
		{"unique_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,initializationType_unique_random)}
		},
	kw_1032[1] = {
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real01,mutationScale)}
		},
	kw_1033[1] = {
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real01,mutationScale)}
		},
	kw_1034[1] = {
		{"mutation_scale",10,0,1,0,0,0.,0.,0,N_mdm(Real01,mutationScale)}
		},
	kw_1035[6] = {
		{"bit_random",8,0,1,1,0,0.,0.,0,N_mdm(lit,mutationType_bit_random)},
		{"mutation_rate",10,0,2,0,0,0.,0.,0,N_mdm(litz,TYPE_DATA_mutationType_null_mutation)},
		{"offset_cauchy",8,1,1,1,kw_1032,0.,0.,0,N_mdm(litc,TYPE_DATA_mutationType_offset_cauchy)},
		{"offset_normal",8,1,1,1,kw_1033,0.,0.,0,N_mdm(litc,TYPE_DATA_mutationType_offset_normal)},
		{"offset_uniform",8,1,1,1,kw_1034,0.,0.,0,N_mdm(litc,TYPE_DATA_mutationType_offset_uniform)},
		{"replace_uniform",8,0,1,1,0,0.,0.,0,N_mdm(lit,mutationType_replace_uniform)}
		},
	kw_1036[4] = {
		{"elitist",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_elitist)},
		{"favor_feasible",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_favor_feasible)},
		{"roulette_wheel",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_roulette_wheel)},
		{"unique_roulette_wheel",8,0,1,1,0,0.,0.,0,N_mdm(lit,replacementType_unique_roulette_wheel)}
		},
	kw_1037[15] = {
		{"convergence_tolerance",10,0,14,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"convergence_type",8,2,3,0,kw_1027},
		{"crossover_type",8,5,11,0,kw_1029},
		{"fitness_type",8,2,1,0,kw_1030},
		{"initialization_type",8,3,10,0,kw_1031},
		{"log_file",11,0,8,0,0,0.,0.,0,N_mdm(str,logFile)},
		{"max_function_evaluations",0x29,0,5,0,0,0.,0.,0,N_mdm(sizet,maxFunctionEvals)},
		{"max_iterations",0x29,0,4,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"model_pointer",11,0,15,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"mutation_type",8,6,12,0,kw_1035},
		{"population_size",0x29,0,7,0,0,0.,0.,0,N_mdm(int,populationSize)},
		{"print_each_pop",8,0,9,0,0,0.,0.,0,N_mdm(true,printPopFlag)},
		{"replacement_type",8,4,2,0,kw_1036},
		{"scaling",8,0,6,0,0,0.,0.,0,N_mdm(true,methodScaling)},
		{"seed",0x19,0,13,0,0,0.,0.,0,N_mdm(int,randomSeed)}
		},
	kw_1038[8] = {
		{"approx_method_name",3,0,1,1,0,0.,0.,4,N_mdm(str,subMethodName)},
		{"approx_method_pointer",3,0,1,1,0,0.,0.,4,N_mdm(str,subMethodPointer)},
		{"approx_model_pointer",3,0,2,2,0,0.,0.,4,N_mdm(str,modelPointer)},
		{"max_iterations",0x29,0,4,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"method_name",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodName)},
		{"method_pointer",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodPointer)},
		{"model_pointer",11,0,2,2,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"replace_points",8,0,3,0,0,0.,0.,0,N_mdm(true,surrBasedGlobalReplacePts)}
		},
	kw_1039[2] = {
		{"filter",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalAcceptLogic_FILTER)},
		{"tr_ratio",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalAcceptLogic_TR_RATIO)}
		},
	kw_1040[7] = {
		{"augmented_lagrangian_objective",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbObj_AUGMENTED_LAGRANGIAN_OBJECTIVE)},
		{"lagrangian_objective",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbObj_LAGRANGIAN_OBJECTIVE)},
		{"linearized_constraints",8,0,2,2,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbCon_LINEARIZED_CONSTRAINTS)},
		{"no_constraints",8,0,2,2,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbCon_NO_CONSTRAINTS)},
		{"original_constraints",8,0,2,2,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbCon_ORIGINAL_CONSTRAINTS)},
		{"original_primary",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbObj_ORIGINAL_PRIMARY)},
		{"single_objective",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalSubProbObj_SINGLE_OBJECTIVE)}
		},
	kw_1041[1] = {
		{"homotopy",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalConstrRelax_HOMOTOPY)}
		},
	kw_1042[4] = {
		{"adaptive_penalty_merit",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalMeritFn_ADAPTIVE_PENALTY_MERIT)},
		{"augmented_lagrangian_merit",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalMeritFn_AUGMENTED_LAGRANGIAN_MERIT)},
		{"lagrangian_merit",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalMeritFn_LAGRANGIAN_MERIT)},
		{"penalty_merit",8,0,1,1,0,0.,0.,0,N_mdm(type,surrBasedLocalMeritFn_PENALTY_MERIT)}
		},
	kw_1043[6] = {
		{"contract_threshold",10,0,3,0,0,0.,0.,0,N_mdm(Real,trustRegionContractTrigger)},
		{"contraction_factor",10,0,5,0,0,0.,0.,0,N_mdm(Real,trustRegionContract)},
		{"expand_threshold",10,0,4,0,0,0.,0.,0,N_mdm(Real,trustRegionExpandTrigger)},
		{"expansion_factor",10,0,6,0,0,0.,0.,0,N_mdm(Real,trustRegionExpand)},
		{"initial_size",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,trustRegionInitSize)},
		{"minimum_size",10,0,2,0,0,0.,0.,0,N_mdm(Real,trustRegionMinSize)}
		},
	kw_1044[16] = {
		{"acceptance_logic",8,2,7,0,kw_1039},
		{"approx_method_name",3,0,1,1,0,0.,0.,9,N_mdm(str,subMethodName)},
		{"approx_method_pointer",3,0,1,1,0,0.,0.,9,N_mdm(str,subMethodPointer)},
		{"approx_model_pointer",3,0,2,2,0,0.,0.,9,N_mdm(str,modelPointer)},
		{"approx_subproblem",8,7,5,0,kw_1040},
		{"constraint_relax",8,1,8,0,kw_1041},
		{"constraint_tolerance",10,0,12,0,0,0.,0.,0,N_mdm(Real,constraintTolerance)},
		{"convergence_tolerance",10,0,11,0,0,0.,0.,0,N_mdm(Real,convergenceTolerance)},
		{"max_iterations",0x29,0,10,0,0,0.,0.,0,N_mdm(sizet,maxIterations)},
		{"merit_function",8,4,6,0,kw_1042},
		{"method_name",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodName)},
		{"method_pointer",11,0,1,1,0,0.,0.,0,N_mdm(str,subMethodPointer)},
		{"model_pointer",11,0,2,2,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"soft_convergence_limit",9,0,3,0,0,0.,0.,0,N_mdm(ushint,softConvLimit)},
		{"trust_region",8,6,9,0,kw_1043,0.,0.,0,0,0,NIDRProblemDescDB::method_tr_final},
		{"truth_surrogate_bypass",8,0,4,0,0,0.,0.,0,N_mdm(true,surrBasedLocalLayerBypass)}
		},
	kw_1045[2] = {
		{"complementary",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_COMPLEMENTARY)},
		{"cumulative",8,0,1,1,0,0.,0.,0,N_mdm(type,distributionType_CUMULATIVE)}
		},
	kw_1046[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_1047[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1046,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_1048[3] = {
		{"central",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_CENTRAL_MOMENTS)},
		{"none",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_NO_MOMENTS)},
		{"standard",8,0,1,1,0,0.,0.,0,N_mdm(type,finalMomentsType_STANDARD_MOMENTS)}
		},
	kw_1049[1] = {
		{"num_gen_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,genReliabilityLevels)}
		},
	kw_1050[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mdm(augment_utype,importApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_1051[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mdm(true,importApproxActive)},
		{"annotated",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1050,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mdm(utype,importApproxFormat_TABULAR_NONE)}
		},
	kw_1052[1] = {
		{"num_probability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,probabilityLevels)}
		},
	kw_1053[4] = {
		{"adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_AIS)},
		{"import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_IS)},
		{"mm_adapt_import",8,0,1,1,0,0.,0.,0,N_mdm(utype,integrationRefine_MMAIS)},
		{"refinement_samples",13,0,2,0,0,0.,0.,0,N_mdm(ivec,refineSamples)}
		},
	kw_1054[1] = {
		{"num_reliability_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,reliabilityLevels)}
		},
	kw_1055[2] = {
		{"parallel",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_PARALLEL)},
		{"series",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTargetReduce_SYSTEM_SERIES)}
		},
	kw_1056[4] = {
		{"gen_reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_GEN_RELIABILITIES)},
		{"probabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_PROBABILITIES)},
		{"reliabilities",8,0,1,1,0,0.,0.,0,N_mdm(type,responseLevelTarget_RELIABILITIES)},
		{"system",8,2,2,0,kw_1055}
		},
	kw_1057[2] = {
		{"compute",8,4,2,0,kw_1056},
		{"num_response_levels",13,0,1,0,0,0.,0.,0,N_mdm(num_resplevs,responseLevels)}
		},
	kw_1058[2] = {
		{"mt19937",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_mt19937)},
		{"rnum2",8,0,1,1,0,0.,0.,0,N_mdm(lit,rngName_rnum2)}
		},
	kw_1059[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mdm(utype,sampleType_SUBMETHOD_RANDOM)}
		},
	kw_1060[2] = {
		{"drop_tolerance",10,0,2,0,0,0.,0.,0,N_mdm(Real,vbdDropTolerance)},
		{"interaction_order",0x19,0,1,0,0,0.,0.,0,N_mdm(ushint,vbdOrder)}
		},
	kw_1061[21] = {
		{"diagonal_covariance",8,0,12,0,0,0.,0.,0,N_mdm(type,covarianceControl_DIAGONAL_COVARIANCE)},
		{"distribution",8,2,10,0,kw_1045},
		{"export_approx_points_file",11,3,14,0,kw_1047,0.,0.,0,N_mdm(str,exportApproxPtsFile)},
		{"export_points_file",3,3,14,0,kw_1047,0.,0.,-1,N_mdm(str,exportApproxPtsFile)},
		{"final_moments",8,3,5,0,kw_1048},
		{"fixed_seed",8,0,16,0,0,0.,0.,0,N_mdm(true,fixedSeedFlag)},
		{"full_covariance",8,0,12,0,0,0.,0.,0,N_mdm(type,covarianceControl_FULL_COVARIANCE)},
		{"gen_reliability_levels",14,1,9,0,kw_1049,0.,0.,0,N_mdm(resplevs,genReliabilityLevels)},
		{"import_approx_points_file",11,4,13,0,kw_1051,0.,0.,0,N_mdm(str,importApproxPtsFile)},
		{"model_pointer",11,0,17,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"probability_levels",14,1,7,0,kw_1052,0.,0.,0,N_mdm(resplevs01,probabilityLevels)},
		{"probability_refinement",8,4,4,0,kw_1053},
		{"reliability_levels",14,1,8,0,kw_1054,0.,0.,0,N_mdm(resplevs,reliabilityLevels)},
		{"response_levels",14,2,6,0,kw_1057,0.,0.,0,N_mdm(resplevs,responseLevels)},
		{"rng",8,2,3,0,kw_1058},
		{"sample_refinement",0,4,4,0,kw_1053,0.,0.,-4},
		{"sample_type",8,2,2,0,kw_1059},
		{"samples",1,0,1,0,0,0.,0.,1,N_mdm(int,samplesOnEmulator)},
		{"samples_on_emulator",9,0,1,0,0,0.,0.,0,N_mdm(int,samplesOnEmulator)},
		{"seed",0x19,0,15,0,0,0.,0.,0,N_mdm(int,randomSeed)},
		{"variance_based_decomp",8,2,11,0,kw_1060,0.,0.,0,N_mdm(true,vbdFlag)}
		},
	kw_1062[4] = {
		{"final_point",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,finalPoint)},
		{"model_pointer",11,0,3,0,0,0.,0.,0,N_mdm(str,modelPointer)},
		{"num_steps",9,0,2,2,0,0.,0.,0,N_mdm(int,numSteps)},
		{"step_vector",14,0,1,1,0,0.,0.,0,N_mdm(RealDL,stepVector)}
		},
	kw_1063[105] = {
		{"acv_sampling",0,24,4,1,kw_59,0.,0.,2,N_mdm(utype,methodName_APPROXIMATE_CONTROL_VARIATE)},
		{"adaptive_sampling",8,19,4,1,kw_73,0.,0.,0,N_mdm(utype,methodName_ADAPTIVE_SAMPLING)},
		{"approximate_control_variate",8,24,4,1,kw_59,0.,0.,0,N_mdm(utype,methodName_APPROXIMATE_CONTROL_VARIATE)},
		{"asynch_pattern_search",8,13,4,1,kw_76,0.,0.,0,N_mdm(utype,methodName_ASYNCH_PATTERN_SEARCH)},
		{"bayes_calibration",8,18,4,1,kw_417,0.,0.,0,N_mdm(utype,methodName_BAYES_CALIBRATION)},
		{"branch_and_bound",8,3,4,1,kw_419,0.,0.,0,N_mdm(utype,methodName_BRANCH_AND_BOUND)},
		{"centered_parameter_study",8,4,4,1,kw_420,0.,0.,0,N_mdm(utype,methodName_CENTERED_PARAMETER_STUDY)},
		{"coliny_apps",0,13,4,1,kw_76,0.,0.,-4,N_mdm(utype,methodName_ASYNCH_PATTERN_SEARCH)},
		{"coliny_beta",8,11,4,1,kw_421,0.,0.,0,N_mdm(utype,methodName_COLINY_BETA)},
		{"coliny_cobyla",8,12,4,1,kw_422,0.,0.,0,N_mdm(utype,methodName_COLINY_COBYLA)},
		{"coliny_direct",8,16,4,1,kw_424,0.,0.,0,N_mdm(utype,methodName_COLINY_DIRECT)},
		{"coliny_ea",8,19,4,1,kw_433,0.,0.,0,N_mdm(utype,methodName_COLINY_EA)},
		{"coliny_pattern_search",8,22,4,1,kw_437,0.,0.,0,N_mdm(utype,methodName_COLINY_PATTERN_SEARCH)},
		{"coliny_solis_wets",8,18,4,1,kw_438,0.,0.,0,N_mdm(utype,methodName_COLINY_SOLIS_WETS)},
		{"conmin_frcg",8,7,4,1,kw_439,0.,0.,0,N_mdm(utype,methodName_CONMIN_FRCG)},
		{"conmin_mfd",8,7,4,1,kw_440,0.,0.,0,N_mdm(utype,methodName_CONMIN_MFD)},
		{"dace",8,15,4,1,kw_444,0.,0.,0,N_mdm(utype,methodName_DACE)},
		{"demo_tpl",8,7,4,1,kw_445,0.,0.,0,N_mdm(utype,methodName_DEMO_TPL)},
		{"dl_solver",11,3,4,1,kw_446,0.,0.,0,N_mdm(utype_lit,TYPE_DATA_methodName_DL_SOLVER)},
		{"dot_bfgs",8,7,4,1,kw_447,0.,0.,0,N_mdm(utype,methodName_DOT_BFGS)},
		{"dot_frcg",8,7,4,1,kw_448,0.,0.,0,N_mdm(utype,methodName_DOT_FRCG)},
		{"dot_mmfd",8,7,4,1,kw_449,0.,0.,0,N_mdm(utype,methodName_DOT_MMFD)},
		{"dot_slp",8,7,4,1,kw_450,0.,0.,0,N_mdm(utype,methodName_DOT_SLP)},
		{"dot_sqp",8,7,4,1,kw_451,0.,0.,0,N_mdm(utype,methodName_DOT_SQP)},
		{"efficient_global",8,14,4,1,kw_465,0.,0.,0,N_mdm(utype,methodName_EFFICIENT_GLOBAL)},
		{"final_solutions",0x29,0,3,0,0,0.,0.,0,N_mdm(sizet,numFinalSolutions)},
		{"fsu_cvt",8,10,4,1,kw_470,0.,0.,0,N_mdm(utype,methodName_FSU_CVT)},
		{"fsu_quasi_mc",8,12,4,1,kw_474},
		{"function_train",8,47,4,1,kw_497,0.,0.,0,N_mdm(utype,methodName_C3_FUNCTION_TRAIN)},
		{"gaussian_process_adaptive_importance_sampling",0,15,4,1,kw_509,0.,0.,6,N_mdm(utype,methodName_GPAIS)},
		{"genie_direct",8,4,4,1,kw_510,0.,0.,0,N_mdm(utype,methodName_GENIE_DIRECT)},
		{"genie_opt_darts",8,4,4,1,kw_511,0.,0.,0,N_mdm(utype,methodName_GENIE_OPT_DARTS)},
		{"global_evidence",8,12,4,1,kw_538,0.,0.,0,N_mdm(utype,methodName_GLOBAL_EVIDENCE)},
		{"global_interval_est",8,11,4,1,kw_559,0.,0.,0,N_mdm(utype,methodName_GLOBAL_INTERVAL_EST)},
		{"global_reliability",8,22,4,1,kw_577,0.,0.,0,N_mdm(utype,methodName_GLOBAL_RELIABILITY)},
		{"gpais",8,15,4,1,kw_509,0.,0.,0,N_mdm(utype,methodName_GPAIS)},
		{"hybrid",8,5,4,1,kw_588,0.,0.,0,N_mdm(utype,methodName_HYBRID)},
		{"id_method",11,0,1,0,0,0.,0.,0,N_mdm(str,idMethod)},
		{"importance_sampling",8,15,4,1,kw_596,0.,0.,0,N_mdm(utype,methodName_IMPORTANCE_SAMPLING)},
		{"list_parameter_study",8,3,4,1,kw_599,0.,0.,0,N_mdm(utype,methodName_LIST_PARAMETER_STUDY)},
		{"local_evidence",8,7,4,1,kw_606,0.,0.,0,N_mdm(utype,methodName_LOCAL_EVIDENCE)},
		{"local_interval_est",8,4,4,1,kw_607,0.,0.,0,N_mdm(utype,methodName_LOCAL_INTERVAL_EST)},
		{"local_reliability",8,10,4,1,kw_619,0.,0.,0,N_mdm(utype,methodName_LOCAL_RELIABILITY)},
		{"mesh_adaptive_search",8,14,4,1,kw_621,0.,0.,0,N_mdm(utype,methodName_MESH_ADAPTIVE_SEARCH)},
		{"mfmc",0,14,4,1,kw_640,0.,0.,9,N_mdm(utype,methodName_MULTIFIDELITY_SAMPLING)},
		{"mlmc",0,17,4,1,kw_666,0.,0.,16,N_mdm(utype,methodName_MULTILEVEL_SAMPLING)},
		{"mlmfmc",0,12,4,1,kw_683,0.,0.,13,N_mdm(utype,methodName_MULTILEVEL_MULTIFIDELITY_SAMPLING)},
		{"moga",8,17,4,1,kw_698,0.,0.,0,N_mdm(utype,methodName_MOGA)},
		{"multi_start",8,7,4,1,kw_702,0.,0.,0,N_mdm(utype,methodName_MULTI_START)},
		{"multidim_parameter_study",8,2,4,1,kw_703,0.,0.,0,N_mdm(utype,methodName_MULTIDIM_PARAMETER_STUDY)},
		{"multifidelity_function_train",8,51,4,1,kw_729,0.,0.,0,N_mdm(utype,methodName_MULTIFIDELITY_FUNCTION_TRAIN)},
		{"multifidelity_mc",0,14,4,1,kw_640,0.,0.,2,N_mdm(utype,methodName_MULTIFIDELITY_SAMPLING)},
		{"multifidelity_polynomial_chaos",8,38,4,1,kw_770,0.,0.,0,N_mdm(utype,methodName_MULTIFIDELITY_POLYNOMIAL_CHAOS)},
		{"multifidelity_sampling",8,14,4,1,kw_640,0.,0.,0,N_mdm(utype,methodName_MULTIFIDELITY_SAMPLING)},
		{"multifidelity_stoch_collocation",8,35,4,1,kw_797,0.,0.,0,N_mdm(utype,methodName_MULTIFIDELITY_STOCH_COLLOCATION)},
		{"multilevel_blue",8,17,4,1,kw_816,0.,0.,0,N_mdm(utype,methodName_MULTILEVEL_BLUE)},
		{"multilevel_function_train",8,49,4,1,kw_840,0.,0.,0,N_mdm(utype,methodName_MULTILEVEL_FUNCTION_TRAIN)},
		{"multilevel_mc",0,17,4,1,kw_666,0.,0.,4,N_mdm(utype,methodName_MULTILEVEL_SAMPLING)},
		{"multilevel_multifidelity_mc",0,12,4,1,kw_683,0.,0.,1,N_mdm(utype,methodName_MULTILEVEL_MULTIFIDELITY_SAMPLING)},
		{"multilevel_multifidelity_sampling",8,12,4,1,kw_683,0.,0.,0,N_mdm(utype,methodName_MULTILEVEL_MULTIFIDELITY_SAMPLING)},
		{"multilevel_polynomial_chaos",8,34,4,1,kw_877,0.,0.,0,N_mdm(utype,methodName_MULTILEVEL_POLYNOMIAL_CHAOS)},
		{"multilevel_sampling",8,17,4,1,kw_666,0.,0.,0,N_mdm(utype,methodName_MULTILEVEL_SAMPLING)},
		{"ncsu_direct",8,9,4,1,kw_878,0.,0.,0,N_mdm(utype,methodName_NCSU_DIRECT)},
		{"nl2sol",8,15,4,1,kw_879,0.,0.,0,N_mdm(utype,methodName_NL2SOL)},
		{"nlpql_sqp",8,5,4,1,kw_880,0.,0.,0,N_mdm(utype,methodName_NLPQL_SQP)},
		{"nlssol_sqp",8,10,4,1,kw_881,0.,0.,0,N_mdm(utype,methodName_NLSSOL_SQP)},
		{"nond_adaptive_sampling",0,19,4,1,kw_73,0.,0.,-65,N_mdm(utype,methodName_ADAPTIVE_SAMPLING)},
		{"nond_bayes_calibration",0,18,4,1,kw_417,0.,0.,-63,N_mdm(utype,methodName_BAYES_CALIBRATION)},
		{"nond_global_evidence",0,12,4,1,kw_538,0.,0.,-36,N_mdm(utype,methodName_GLOBAL_EVIDENCE)},
		{"nond_global_interval_est",0,11,4,1,kw_559,0.,0.,-36,N_mdm(utype,methodName_GLOBAL_INTERVAL_EST)},
		{"nond_global_reliability",0,22,4,1,kw_577,0.,0.,-36,N_mdm(utype,methodName_GLOBAL_RELIABILITY)},
		{"nond_importance_sampling",0,15,4,1,kw_596,0.,0.,-33,N_mdm(utype,methodName_IMPORTANCE_SAMPLING)},
		{"nond_local_evidence",0,7,4,1,kw_606,0.,0.,-32,N_mdm(utype,methodName_LOCAL_EVIDENCE)},
		{"nond_local_interval_est",0,4,4,1,kw_607,0.,0.,-32,N_mdm(utype,methodName_LOCAL_INTERVAL_EST)},
		{"nond_local_reliability",0,10,4,1,kw_619,0.,0.,-32,N_mdm(utype,methodName_LOCAL_RELIABILITY)},
		{"nond_pof_darts",0,11,4,1,kw_890,0.,0.,16,N_mdm(utype,methodName_POF_DARTS)},
		{"nond_polynomial_chaos",0,37,4,1,kw_935,0.,0.,16,N_mdm(utype,methodName_POLYNOMIAL_CHAOS)},
		{"nond_rkd_darts",0,11,4,1,kw_944,0.,0.,18,N_mdm(utype,methodName_RKD_DARTS)},
		{"nond_sampling",0,21,4,1,kw_972,0.,0.,19,N_mdm(utype,methodName_RANDOM_SAMPLING)},
		{"nond_stoch_collocation",0,32,4,1,kw_996,0.,0.,21,N_mdm(utype,methodName_STOCH_COLLOCATION)},
		{"nonlinear_cg",8,5,4,1,kw_997,0.,0.,0,N_mdm(utype,methodName_NONLINEAR_CG)},
		{"nowpac",8,5,4,1,kw_999,0.,0.,0,N_mdm(utype,methodName_MIT_NOWPAC)},
		{"npsol_sqp",8,10,4,1,kw_1000,0.,0.,0,N_mdm(utype,methodName_NPSOL_SQP)},
		{"optpp_cg",8,8,4,1,kw_1001,0.,0.,0,N_mdm(utype,methodName_OPTPP_CG)},
		{"optpp_fd_newton",8,12,4,1,kw_1004,0.,0.,0,N_mdm(utype,methodName_OPTPP_FD_NEWTON)},
		{"optpp_g_newton",8,12,4,1,kw_1007,0.,0.,0,N_mdm(utype,methodName_OPTPP_G_NEWTON)},
		{"optpp_newton",8,12,4,1,kw_1010,0.,0.,0,N_mdm(utype,methodName_OPTPP_NEWTON)},
		{"optpp_pds",8,6,4,1,kw_1011,0.,0.,0,N_mdm(utype,methodName_OPTPP_PDS)},
		{"optpp_q_newton",8,12,4,1,kw_1014,0.,0.,0,N_mdm(utype,methodName_OPTPP_Q_NEWTON)},
		{"output",8,5,2,0,kw_1015},
		{"pareto_set",8,10,4,1,kw_1019,0.,0.,0,N_mdm(utype,methodName_PARETO_SET)},
		{"pof_darts",8,11,4,1,kw_890,0.,0.,0,N_mdm(utype,methodName_POF_DARTS)},
		{"polynomial_chaos",8,37,4,1,kw_935,0.,0.,0,N_mdm(utype,methodName_POLYNOMIAL_CHAOS)},
		{"psuade_moat",8,4,4,1,kw_1020,0.,0.,0,N_mdm(utype,methodName_PSUADE_MOAT)},
		{"richardson_extrap",8,7,4,1,kw_1021,0.,0.,0,N_mdm(utype,methodName_RICHARDSON_EXTRAP)},
		{"rkd_darts",8,11,4,1,kw_944,0.,0.,0,N_mdm(utype,methodName_RKD_DARTS)},
		{"rol",8,7,4,1,kw_1022,0.,0.,0,N_mdm(utype,methodName_ROL)},
		{"sampling",8,21,4,1,kw_972,0.,0.,0,N_mdm(utype,methodName_RANDOM_SAMPLING)},
		{"snowpac",8,6,4,1,kw_1024,0.,0.,0,N_mdm(utype,methodName_MIT_SNOWPAC)},
		{"soga",8,15,4,1,kw_1037,0.,0.,0,N_mdm(utype,methodName_SOGA)},
		{"stoch_collocation",8,32,4,1,kw_996,0.,0.,0,N_mdm(utype,methodName_STOCH_COLLOCATION)},
		{"surrogate_based_global",8,8,4,1,kw_1038,0.,0.,0,N_mdm(utype,methodName_SURROGATE_BASED_GLOBAL)},
		{"surrogate_based_local",8,16,4,1,kw_1044,0.,0.,0,N_mdm(utype,methodName_SURROGATE_BASED_LOCAL)},
		{"surrogate_based_uq",8,21,4,1,kw_1061,0.,0.,0,N_mdm(utype,methodName_SURROGATE_BASED_UQ)},
		{"vector_parameter_study",8,4,4,1,kw_1062,0.,0.,0,N_mdm(utype,methodName_VECTOR_PARAMETER_STUDY)}
		},
	kw_1064[1] = {
		{"refinement_samples",13,0,1,0,0,0.,0.,0,N_mom(ivec,refineSamples)}
		},
	kw_1065[3] = {
		{"local_gradient",8,0,1,1,0,0.,0.,0,N_mom(utype,subspaceNormalization_SUBSPACE_NORM_LOCAL_GRAD)},
		{"mean_gradient",8,0,1,1,0,0.,0.,0,N_mom(utype,subspaceNormalization_SUBSPACE_NORM_MEAN_GRAD)},
		{"mean_value",8,0,1,1,0,0.,0.,0,N_mom(utype,subspaceNormalization_SUBSPACE_NORM_MEAN_VALUE)}
		},
	kw_1066[2] = {
		{"lhs",8,0,1,1,0,0.,0.,0,N_mom(utype,subspaceSampleType_SUBMETHOD_LHS)},
		{"random",8,0,1,1,0,0.,0.,0,N_mom(utype,subspaceSampleType_SUBMETHOD_RANDOM)}
		},
	kw_1067[7] = {
		{"decrease",8,0,1,0,0,0.,0.,0,N_mom(utype,subspaceIdCVMethod_DECREASE_TOLERANCE)},
		{"decrease_tolerance",10,0,3,0,0,0.,0.,0,N_mom(Real,decreaseTolerance)},
		{"exhaustive",8,0,5,0,0,0.,0.,0,N_mom(false,subspaceCVIncremental)},
		{"max_rank",9,0,4,0,0,0.,0.,0,N_mom(int,subspaceCVMaxRank)},
		{"minimum",8,0,1,0,0,0.,0.,0,N_mom(utype,subspaceIdCVMethod_MINIMUM_METRIC)},
		{"relative",8,0,1,0,0,0.,0.,0,N_mom(utype,subspaceIdCVMethod_RELATIVE_TOLERANCE)},
		{"relative_tolerance",10,0,2,0,0,0.,0.,0,N_mom(Real,relTolerance)}
		},
	kw_1068[1] = {
		{"truncation_tolerance",10,0,1,0,0,0.,0.,0,N_mom(Real,truncationTolerance)}
		},
	kw_1069[4] = {
		{"bing_li",8,0,1,0,0,0.,0.,0,N_mom(true,subspaceIdBingLi)},
		{"constantine",8,0,2,0,0,0.,0.,0,N_mom(true,subspaceIdConstantine)},
		{"cross_validation",8,7,4,0,kw_1067,0.,0.,0,N_mom(true,subspaceIdCV)},
		{"energy",8,1,3,0,kw_1068,0.,0.,0,N_mom(true,subspaceIdEnergy)}
		},
	kw_1070[9] = {
		{"actual_model_pointer",3,0,1,1,0,0.,0.,8,N_mom(str,truthModelPointer)},
		{"bootstrap_samples",9,0,6,0,0,0.,0.,0,N_mom(int,numReplicates)},
		{"build_surrogate",8,1,7,0,kw_1064,0.,0.,0,N_mom(true,subspaceBuildSurrogate)},
		{"dimension",9,0,5,0,0,0.,0.,0,N_mom(int,subspaceDimension)},
		{"initial_samples",9,0,2,0,0,0.,0.,0,N_mom(int,initialSamples)},
		{"normalization",8,3,8,0,kw_1065},
		{"sample_type",8,2,3,0,kw_1066},
		{"truncation_method",8,4,4,0,kw_1069},
		{"truth_model_pointer",11,0,1,1,0,0.,0.,0,N_mom(str,truthModelPointer)}
		},
	kw_1071[1] = {
		{"collocation_ratio",10,0,1,1,0,0.,0.,0,N_mom(Real,adaptedBasisCollocRatio)}
		},
	kw_1072[2] = {
		{"ranked",8,0,1,1,0,0.,0.,0,N_mom(type,method_rotation_ROTATION_METHOD_RANKED)},
		{"unranked",8,0,1,1,0,0.,0.,0,N_mom(type,method_rotation_ROTATION_METHOD_UNRANKED)}
		},
	kw_1073[4] = {
		{"dimension",9,0,2,0,0,0.,0.,0,N_mom(int,subspaceDimension)},
		{"expansion_order",9,1,1,1,kw_1071,0.,0.,0,N_mom(ushint,adaptedBasisExpOrder)},
		{"rotation_method",8,2,3,0,kw_1072},
		{"sparse_grid_level",9,0,1,1,0,0.,0.,0,N_mom(ushint,adaptedBasisSparseGridLev)}
		},
	kw_1074[3] = {
		{"actual_model_pointer",3,4,1,1,kw_1073,0.,0.,2,N_mom(str,truthModelPointer)},
		{"truncation_tolerance",10,0,2,0,0,0.,0.,0,N_mom(Real,adaptedBasisTruncationTolerance)},
		{"truth_model_pointer",11,4,1,1,kw_1073,0.,0.,0,N_mom(str,truthModelPointer)}
		},
	kw_1075[1] = {
		{"optional_interface_responses_pointer",11,0,1,0,0,0.,0.,0,N_mom(str,optionalInterfRespPointer)}
		},
	kw_1076[2] = {
		{"master",8,0,1,1,0,0.,0.,0,N_mom(type,subMethodScheduling_MASTER_SCHEDULING)},
		{"peer",8,0,1,1,0,0.,0.,0,N_mom(type,subMethodScheduling_PEER_SCHEDULING)}
		},
	kw_1077[8] = {
		{"identity_response_mapping",8,0,8,0,0,0.,0.,0,N_mom(true,identityRespMap)},
		{"iterator_scheduling",8,2,2,0,kw_1076},
		{"iterator_servers",0x19,0,1,0,0,0.,0.,0,N_mom(int,subMethodServers)},
		{"primary_response_mapping",14,0,6,0,0,0.,0.,0,N_mom(RealDL,primaryRespCoeffs)},
		{"primary_variable_mapping",15,0,4,0,0,0.,0.,0,N_mom(strL,primaryVarMaps)},
		{"processors_per_iterator",0x19,0,3,0,0,0.,0.,0,N_mom(int,subMethodProcs)},
		{"secondary_response_mapping",14,0,7,0,0,0.,0.,0,N_mom(RealDL,secondaryRespCoeffs)},
		{"secondary_variable_mapping",15,0,5,0,0,0.,0.,0,N_mom(strL,secondaryVarMaps)}
		},
	kw_1078[2] = {
		{"optional_interface_pointer",11,1,1,0,kw_1075,0.,0.,0,N_mom(str,interfacePointer)},
		{"sub_method_pointer",11,8,2,1,kw_1077,0.,0.,0,N_mom(str,subMethodPointer)}
		},
	kw_1079[2] = {
		{"exponential",8,0,1,1,0,0.,0.,0,N_mom(utype,analyticCovIdForm_EXP_L1)},
		{"squared_exponential",8,0,1,1,0,0.,0.,0,N_mom(utype,analyticCovIdForm_EXP_L2)}
		},
	kw_1080[3] = {
		{"analytic_covariance",8,2,1,1,kw_1079},
		{"dace_method_pointer",11,0,1,1,0,0.,0.,0,N_mom(str,subMethodPointer)},
		{"rf_data_file",11,0,1,1,0,0.,0.,0,N_mom(str,rfDataFileName)}
		},
	kw_1081[2] = {
		{"karhunen_loeve",8,0,1,1,0,0.,0.,0,N_mom(utype,randomFieldIdForm_RF_KARHUNEN_LOEVE)},
		{"principal_components",8,0,1,1,0,0.,0.,0,N_mom(utype,randomFieldIdForm_RF_PCA_GP)}
		},
	kw_1082[5] = {
		{"build_source",8,3,1,0,kw_1080},
		{"expansion_bases",9,0,3,0,0,0.,0.,0,N_mom(int,subspaceDimension)},
		{"expansion_form",8,2,2,0,kw_1081},
		{"propagation_model_pointer",11,0,5,1,0,0.,0.,0,N_mom(str,propagationModelPointer)},
		{"truncation_tolerance",10,0,4,0,0,0.,0.,0,N_mom(Real,truncationTolerance)}
		},
	kw_1083[4] = {
		{"cost_recovery_metadata",11,0,3,0,0,0.,0.,0,N_mom(str,costRecoveryMetadata)},
		{"interface_pointer",11,0,1,0,0,0.,0.,0,N_mom(str,interfacePointer)},
		{"solution_level_control",11,0,2,0,0,0.,0.,0,N_mom(str,solutionLevelControl)},
		{"solution_level_cost",14,0,3,0,0,0.,0.,0,N_mom(RealDL,solutionLevelCost)}
		},
	kw_1084[2] = {
		{"approximation_models",15,0,1,0,0,0.,0.,0,N_mom(strL,ensembleModelPointers)},
		{"unordered_model_fidelities",7,0,1,0,0,0.,0.,-1,N_mom(strL,ensembleModelPointers)}
		},
	kw_1085[6] = {
		{"additive",8,0,2,2,0,0.,0.,0,N_mom(type,approxCorrectionType_ADDITIVE_CORRECTION)},
		{"combined",8,0,2,2,0,0.,0.,0,N_mom(type,approxCorrectionType_COMBINED_CORRECTION)},
		{"first_order",8,0,1,1,0,0.,0.,0,N_mom(order,approxCorrectionOrder_1)},
		{"multiplicative",8,0,2,2,0,0.,0.,0,N_mom(type,approxCorrectionType_MULTIPLICATIVE_CORRECTION)},
		{"second_order",8,0,1,1,0,0.,0.,0,N_mom(order,approxCorrectionOrder_2)},
		{"zeroth_order",8,0,1,1,0,0.,0.,0,N_mom(order,approxCorrectionOrder_0)}
		},
	kw_1086[1] = {
		{"correction",8,6,1,0,kw_1085}
		},
	kw_1087[4] = {
		{"actual_model_pointer",3,2,1,1,kw_1084,0.,0.,3,N_mom(str,truthModelPointer)},
		{"model_fidelity_sequence",7,1,1,1,kw_1086,0.,0.,1,N_mom(strL,ensembleModelPointers)},
		{"ordered_model_fidelities",15,1,1,1,kw_1086,0.,0.,0,N_mom(strL,ensembleModelPointers)},
		{"truth_model_pointer",11,2,1,1,kw_1084,0.,0.,0,N_mom(str,truthModelPointer)}
		},
	kw_1088[1] = {
		{"use_variable_labels",8,0,1,0,0,0.,0.,0,N_mom(true,importChalUseVariableLabels)}
		},
	kw_1089[1] = {
		{"use_variable_labels",8,0,1,0,0,0.,0.,0,N_mom(true,importChalUseVariableLabels)}
		},
	kw_1090[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,importChallengeFormat_TABULAR_EVAL_ID)},
		{"header",8,1,1,0,kw_1089,0.,0.,0,N_mom(augment_utype,importChallengeFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,importChallengeFormat_TABULAR_IFACE_ID)}
		},
	kw_1091[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mom(true,importChallengeActive)},
		{"annotated",8,1,1,0,kw_1088,0.,0.,0,N_mom(utype,importChallengeFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1090,0.,0.,0,N_mom(utype,importChallengeFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mom(utype,importChallengeFormat_TABULAR_NONE)}
		},
	kw_1092[6] = {
		{"additive",8,0,2,2,0,0.,0.,0,N_mom(type,approxCorrectionType_ADDITIVE_CORRECTION)},
		{"combined",8,0,2,2,0,0.,0.,0,N_mom(type,approxCorrectionType_COMBINED_CORRECTION)},
		{"first_order",8,0,1,1,0,0.,0.,0,N_mom(order,approxCorrectionOrder_1)},
		{"multiplicative",8,0,2,2,0,0.,0.,0,N_mom(type,approxCorrectionType_MULTIPLICATIVE_CORRECTION)},
		{"second_order",8,0,1,1,0,0.,0.,0,N_mom(order,approxCorrectionOrder_2)},
		{"zeroth_order",8,0,1,1,0,0.,0.,0,N_mom(order,approxCorrectionOrder_0)}
		},
	kw_1093[1] = {
		{"folds",0x19,0,1,0,0,0.,0.,0,N_mom(int,refineCVFolds)}
		},
	kw_1094[5] = {
		{"convergence_tolerance",10,0,3,0,0,0.,0.,0,N_mom(Real,convergenceTolerance)},
		{"cross_validation_metric",11,1,5,0,kw_1093,0.,0.,0,N_mom(str,refineCVMetric)},
		{"max_function_evaluations",0x19,0,2,0,0,0.,0.,0,N_mom(sizet,maxFunctionEvals)},
		{"max_iterations",0x19,0,1,0,0,0.,0.,0,N_mom(sizet,maxIterations)},
		{"soft_convergence_limit",0x29,0,4,0,0,0.,0.,0,N_mom(int,softConvergenceLimit)}
		},
	kw_1095[1] = {
		{"auto_refinement",8,5,1,0,kw_1094,0.,0.,0,N_mom(true,autoRefine)}
		},
	kw_1096[2] = {
		{"folds",9,0,1,0,0,0.,0.,0,N_mom(int,numFolds)},
		{"percent",10,0,1,0,0,0.,0.,0,N_mom(Real,percentFold)}
		},
	kw_1097[2] = {
		{"cross_validation",8,2,1,0,kw_1096,0.,0.,0,N_mom(true,crossValidateFlag)},
		{"press",8,0,2,0,0,0.,0.,0,N_mom(true,pressFlag)}
		},
	kw_1098[2] = {
		{"gradient_threshold",10,0,1,1,0,0.,0.,0,N_mom(Real,discontGradThresh)},
		{"jump_threshold",10,0,1,1,0,0.,0.,0,N_mom(Real,discontJumpThresh)}
		},
	kw_1099[3] = {
		{"cell_type",11,0,1,0,0,0.,0.,0,N_mom(str,decompCellType)},
		{"discontinuity_detection",8,2,3,0,kw_1098,0.,0.,0,N_mom(true,decompDiscontDetect)},
		{"support_layers",9,0,2,0,0,0.,0.,0,N_mom(int,decompSupportLayers)}
		},
	kw_1100[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,exportApproxVarianceFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,exportApproxVarianceFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,exportApproxVarianceFormat_TABULAR_IFACE_ID)}
		},
	kw_1101[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mom(utype,exportApproxVarianceFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1100,0.,0.,0,N_mom(utype,exportApproxVarianceFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mom(utype,exportApproxVarianceFormat_TABULAR_NONE)}
		},
	kw_1102[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1103[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_1102}
		},
	kw_1104[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1105[5] = {
		{"constant",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_constant)},
		{"linear",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_linear)},
		{"none",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_none)},
		{"quadratic",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_quadratic)},
		{"reduced_quadratic",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_reduced_quadratic)}
		},
	kw_1106[8] = {
		{"export_approx_variance_file",11,3,5,0,kw_1101,0.,0.,0,N_mom(str,exportApproxVarianceFile)},
		{"export_model",8,2,6,0,kw_1103,0.,0.,0,N_mom(true,exportSurrogate)},
		{"find_nugget",9,0,3,0,0,0.,0.,0,N_mom(shint,krigingFindNugget)},
		{"import_model",8,3,7,0,kw_1104,0.,0.,0,N_mom(true,importSurrogate)},
		{"nugget",0x1a,0,3,0,0,0.,0.,0,N_mom(Real,krigingNugget)},
		{"num_restarts",0x19,0,2,0,0,1.,0.,0,N_mom(int,numRestarts)},
		{"options_file",11,0,4,0,0,0.,0.,0,N_mom(str,advancedOptionsFilename)},
		{"trend",8,5,1,0,kw_1105}
		},
	kw_1107[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1108[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_1107}
		},
	kw_1109[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1110[4] = {
		{"basis_order",0x29,0,1,1,0,0.,0.,0,N_mom(shint,polynomialOrder)},
		{"export_model",8,2,3,0,kw_1108,0.,0.,0,N_mom(true,exportSurrogate)},
		{"import_model",8,3,4,0,kw_1109,0.,0.,0,N_mom(true,importSurrogate)},
		{"options_file",11,0,2,0,0,0.,0.,0,N_mom(str,advancedOptionsFilename)}
		},
	kw_1111[1] = {
		{"class_path_and_name",11,0,1,1,0,0.,0.,0,N_mom(str,moduleAndClassName)}
		},
	kw_1112[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,exportApproxFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,exportApproxFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,exportApproxFormat_TABULAR_IFACE_ID)}
		},
	kw_1113[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mom(utype,exportApproxFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1112,0.,0.,0,N_mom(utype,exportApproxFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mom(utype,exportApproxFormat_TABULAR_NONE)}
		},
	kw_1114[1] = {
		{"dimension_preference",14,0,1,0,0,0.,0.,0,N_mdm(RealDL,anisoDimPref)}
		},
	kw_1115[1] = {
		{"l2_penalty",10,0,1,1,0,0.,0.,0,N_mom(Real,regressionL2Penalty)}
		},
	kw_1116[2] = {
		{"ls",8,0,1,1,0,0.,0.,0,N_mom(type,regressionType_FT_LS)},
		{"rls2",8,1,1,1,kw_1115,0.,0.,0,N_mom(type,regressionType_FT_RLS2)}
		},
	kw_1117[20] = {
		{"adapt_order",8,0,10,0,0,0.,0.,0,N_mom(true,adaptOrder)},
		{"adapt_rank",8,0,15,0,0,0.,0.,0,N_mom(true,adaptRank)},
		{"arithmetic_tolerance",10,0,8,0,0,0.,0.,0,N_mom(Real,statsRoundingTol)},
		{"kick_order",0x19,0,11,0,0,0.,0.,0,N_mom(ushint,kickOrder)},
		{"kick_rank",0x19,0,16,0,0,0.,0.,0,N_mom(sizet,kickRank)},
		{"max_cross_iterations",0x29,0,3,0,0,0.,0.,0,N_mom(int,maxCrossIterations)},
		{"max_cv_order_candidates",0x29,0,13,0,0,0.,0.,0,N_mom(ushint,maxCVOrderCandidates)},
		{"max_cv_rank_candidates",0x29,0,18,0,0,0.,0.,0,N_mom(sizet,maxCVRankCandidates)},
		{"max_order",0x29,0,12,0,0,0.,0.,0,N_mom(ushint,maxOrder)},
		{"max_rank",0x29,0,17,0,0,0.,0.,0,N_mom(sizet,maxRank)},
		{"max_solver_iterations",0x29,0,2,0,0,0.,0.,0,N_mom(sizet,maxSolverIterations)},
		{"order",0x21,1,9,0,kw_1114,0.,0.,6,N_mom(ushint,startOrder)},
		{"rank",0x21,0,14,0,0,0.,0.,6,N_mom(sizet,startRank)},
		{"regression_type",8,2,1,0,kw_1116},
		{"response_scaling",8,0,5,0,0,0.,0.,0,N_mom(true,respScalingFlag)},
		{"rounding_tolerance",10,0,7,0,0,0.,0.,0,N_mom(Real,solverRoundingTol)},
		{"solver_tolerance",10,0,4,0,0,0.,0.,0,N_mom(Real,solverTol)},
		{"start_order",0x29,1,9,0,kw_1114,0.,0.,0,N_mom(ushint,startOrder)},
		{"start_rank",0x29,0,14,0,0,0.,0.,0,N_mom(sizet,startRank)},
		{"tensor_grid",8,0,6,0,0,0.,0.,0,N_mom(true,tensorGridFlag)}
		},
	kw_1118[3] = {
		{"constant",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_constant)},
		{"linear",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_linear)},
		{"reduced_quadratic",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_reduced_quadratic)}
		},
	kw_1119[2] = {
		{"point_selection",8,0,1,0,0,0.,0.,0,N_mom(true,pointSelection)},
		{"trend",8,3,2,0,kw_1118}
		},
	kw_1120[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,exportApproxVarianceFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,exportApproxVarianceFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,exportApproxVarianceFormat_TABULAR_IFACE_ID)}
		},
	kw_1121[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_mom(utype,exportApproxVarianceFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1120,0.,0.,0,N_mom(utype,exportApproxVarianceFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mom(utype,exportApproxVarianceFormat_TABULAR_NONE)}
		},
	kw_1122[4] = {
		{"algebraic_console",8,0,4,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_CONSOLE)},
		{"algebraic_file",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_FILE)},
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1123[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,4,2,1,kw_1122}
		},
	kw_1124[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1125[4] = {
		{"constant",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_constant)},
		{"linear",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_linear)},
		{"quadratic",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_quadratic)},
		{"reduced_quadratic",8,0,1,1,0,0.,0.,0,N_mom(lit,trendOrder_reduced_quadratic)}
		},
	kw_1126[8] = {
		{"correlation_lengths",14,0,5,0,0,0.,0.,0,N_mom(RealDL,krigingCorrelations)},
		{"export_model",8,2,6,0,kw_1123,0.,0.,0,N_mom(true,exportSurrogate)},
		{"find_nugget",9,0,4,0,0,0.,0.,0,N_mom(shint,krigingFindNugget)},
		{"import_model",8,3,7,0,kw_1124,0.,0.,0,N_mom(true,importSurrogate)},
		{"max_trials",0x19,0,3,0,0,0.,0.,0,N_mom(shint,krigingMaxTrials)},
		{"nugget",0x1a,0,4,0,0,0.,0.,0,N_mom(Real,krigingNugget)},
		{"optimization_method",11,0,2,0,0,0.,0.,0,N_mom(str,krigingOptMethod)},
		{"trend",8,4,1,0,kw_1125}
		},
	kw_1127[3] = {
		{"dakota",8,2,1,1,kw_1119,0.,0.,0,N_mom(lit,surrogateType_global_gaussian)},
		{"export_approx_variance_file",11,3,2,0,kw_1121,0.,0.,0,N_mom(str,exportApproxVarianceFile)},
		{"surfpack",8,8,1,1,kw_1126,0.,0.,0,N_mom(lit,surrogateType_global_kriging)}
		},
	kw_1128[1] = {
		{"use_variable_labels",8,0,1,0,0,0.,0.,0,N_mom(true,importUseVariableLabels)}
		},
	kw_1129[1] = {
		{"use_variable_labels",8,0,1,0,0,0.,0.,0,N_mom(true,importUseVariableLabels)}
		},
	kw_1130[3] = {
		{"eval_id",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,importBuildFormat_TABULAR_EVAL_ID)},
		{"header",8,1,1,0,kw_1129,0.,0.,0,N_mom(augment_utype,importBuildFormat_TABULAR_HEADER)},
		{"interface_id",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,importBuildFormat_TABULAR_IFACE_ID)}
		},
	kw_1131[4] = {
		{"active_only",8,0,2,0,0,0.,0.,0,N_mom(true,importBuildActive)},
		{"annotated",8,1,1,0,kw_1128,0.,0.,0,N_mom(utype,importBuildFormat_TABULAR_ANNOTATED)},
		{"custom_annotated",8,3,1,0,kw_1130,0.,0.,0,N_mom(utype,importBuildFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_mom(utype,importBuildFormat_TABULAR_NONE)}
		},
	kw_1132[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1133[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_1132}
		},
	kw_1134[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1135[2] = {
		{"cubic",8,0,1,1,0,0.,0.,0,N_mom(lit,marsInterpolation_cubic)},
		{"linear",8,0,1,1,0,0.,0.,0,N_mom(lit,marsInterpolation_linear)}
		},
	kw_1136[4] = {
		{"export_model",8,2,3,0,kw_1133,0.,0.,0,N_mom(true,exportSurrogate)},
		{"import_model",8,3,4,0,kw_1134,0.,0.,0,N_mom(true,importSurrogate)},
		{"interpolation",8,2,2,0,kw_1135},
		{"max_bases",9,0,1,0,0,0.,0.,0,N_mom(shint,marsMaxBases)}
		},
	kw_1137[2] = {
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1138[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,2,2,1,kw_1137}
		},
	kw_1139[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1140[5] = {
		{"basis_order",0x29,0,1,0,0,0.,0.,0,N_mom(shint,polynomialOrder)},
		{"export_model",8,2,3,0,kw_1138,0.,0.,0,N_mom(true,exportSurrogate)},
		{"import_model",8,3,4,0,kw_1139,0.,0.,0,N_mom(true,importSurrogate)},
		{"poly_order",0x21,0,1,0,0,0.,0.,-3,N_mom(shint,polynomialOrder)},
		{"weight_function",9,0,2,0,0,0.,0.,0,N_mom(shint,mlsWeightFunction)}
		},
	kw_1141[4] = {
		{"algebraic_console",8,0,4,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_CONSOLE)},
		{"algebraic_file",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_FILE)},
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1142[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,4,2,1,kw_1141}
		},
	kw_1143[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1144[6] = {
		{"export_model",8,2,4,0,kw_1142,0.,0.,0,N_mom(true,exportSurrogate)},
		{"import_model",8,3,5,0,kw_1143,0.,0.,0,N_mom(true,importSurrogate)},
		{"max_nodes",9,0,1,0,0,0.,0.,0,N_mom(shint,annNodes)},
		{"nodes",1,0,1,0,0,0.,0.,-1,N_mom(shint,annNodes)},
		{"random_weight",9,0,3,0,0,0.,0.,0,N_mom(shint,annRandomWeight)},
		{"range",10,0,2,0,0,0.,0.,0,N_mom(Real,annRange)}
		},
	kw_1145[4] = {
		{"algebraic_console",8,0,4,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_CONSOLE)},
		{"algebraic_file",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_FILE)},
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1146[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,4,2,1,kw_1145}
		},
	kw_1147[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1148[6] = {
		{"basis_order",0x29,0,1,1,0,0.,0.,0,N_mom(shint,polynomialOrder)},
		{"cubic",8,0,1,1,0,0.,0.,0,N_mom(order,polynomialOrder_3)},
		{"export_model",8,2,2,0,kw_1146,0.,0.,0,N_mom(true,exportSurrogate)},
		{"import_model",8,3,3,0,kw_1147,0.,0.,0,N_mom(true,importSurrogate)},
		{"linear",8,0,1,1,0,0.,0.,0,N_mom(order,polynomialOrder_1)},
		{"quadratic",8,0,1,1,0,0.,0.,0,N_mom(order,polynomialOrder_2)}
		},
	kw_1149[4] = {
		{"algebraic_console",8,0,4,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_CONSOLE)},
		{"algebraic_file",8,0,3,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_ALGEBRAIC_FILE)},
		{"binary_archive",8,0,2,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_BINARY_ARCHIVE)},
		{"text_archive",8,0,1,0,0,0.,0.,0,N_mom(augment_utype,modelExportFormat_TEXT_ARCHIVE)}
		},
	kw_1150[2] = {
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelExportPrefix)},
		{"formats",8,4,2,1,kw_1149}
		},
	kw_1151[3] = {
		{"binary_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_BINARY_ARCHIVE)},
		{"filename_prefix",11,0,1,0,0,0.,0.,0,N_mom(str,modelImportPrefix)},
		{"text_archive",8,0,2,1,0,0.,0.,0,N_mom(augment_utype,modelImportFormat_TEXT_ARCHIVE)}
		},
	kw_1152[6] = {
		{"bases",9,0,1,0,0,0.,0.,0,N_mom(shint,rbfBases)},
		{"export_model",8,2,5,0,kw_1150,0.,0.,0,N_mom(true,exportSurrogate)},
		{"import_model",8,3,6,0,kw_1151,0.,0.,0,N_mom(true,importSurrogate)},
		{"max_pts",9,0,2,0,0,0.,0.,0,N_mom(shint,rbfMaxPts)},
		{"max_subsets",9,0,4,0,0,0.,0.,0,N_mom(shint,rbfMaxSubsets)},
		{"min_partition",9,0,3,0,0,0.,0.,0,N_mom(shint,rbfMinPartition)}
		},
	kw_1153[3] = {
		{"all",8,0,1,1,0,0.,0.,0,N_mom(lit,approxPointReuse_all)},
		{"none",8,0,1,1,0,0.,0.,0,N_mom(lit,approxPointReuse_none)},
		{"region",8,0,1,1,0,0.,0.,0,N_mom(lit,approxPointReuse_region)}
		},
	kw_1154[31] = {
		{"actual_model_pointer",3,0,4,0,0,0.,0.,29,N_mom(str,truthModelPointer)},
		{"challenge_points_file",3,4,11,0,kw_1091,0.,0.,13,N_mom(str,importChallengePtsFile)},
		{"correction",8,6,9,0,kw_1092},
		{"dace_method_pointer",11,1,4,0,kw_1095,0.,0.,0,N_mom(str,subMethodPointer)},
		{"diagnostics",7,2,10,0,kw_1097,0.,0.,14,N_mom(strL,diagMetrics)},
		{"domain_decomposition",8,3,2,0,kw_1099,0.,0.,0,N_mom(true,domainDecomp)},
		{"experimental_gaussian_process",8,8,1,1,kw_1106,0.,0.,0,N_mom(lit,surrogateType_global_exp_gauss_proc)},
		{"experimental_polynomial",8,4,1,1,kw_1110,0.,0.,0,N_mom(lit,surrogateType_global_exp_poly)},
		{"experimental_python",8,1,1,1,kw_1111,0.,0.,0,N_mom(lit,surrogateType_global_exp_python)},
		{"export_approx_points_file",11,3,7,0,kw_1113,0.,0.,0,N_mom(str,exportApproxPtsFile)},
		{"export_points_file",3,3,7,0,kw_1113,0.,0.,-1,N_mom(str,exportApproxPtsFile)},
		{"function_train",8,20,1,1,kw_1117,0.,0.,0,N_mom(lit,surrogateType_global_function_train)},
		{"gaussian_process",8,3,1,1,kw_1127},
		{"import_build_points_file",11,4,6,0,kw_1131,0.,0.,0,N_mom(str,importBuildPtsFile)},
		{"import_challenge_points_file",11,4,11,0,kw_1091,0.,0.,0,N_mom(str,importChallengePtsFile)},
		{"import_points_file",3,4,6,0,kw_1131,0.,0.,-2,N_mom(str,importBuildPtsFile)},
		{"kriging",0,3,1,1,kw_1127,0.,0.,-4},
		{"mars",8,4,1,1,kw_1136,0.,0.,0,N_mom(lit,surrogateType_global_mars)},
		{"metrics",15,2,10,0,kw_1097,0.,0.,0,N_mom(strL,diagMetrics)},
		{"minimum_points",8,0,3,0,0,0.,0.,0,N_mom(type,pointsManagement_MINIMUM_POINTS)},
		{"moving_least_squares",8,5,1,1,kw_1140,0.,0.,0,N_mom(lit,surrogateType_global_moving_least_squares)},
		{"neural_network",8,6,1,1,kw_1144,0.,0.,0,N_mom(lit,surrogateType_global_neural_network)},
		{"polynomial",8,6,1,1,kw_1148,0.,0.,0,N_mom(lit,surrogateType_global_polynomial)},
		{"radial_basis",8,6,1,1,kw_1152,0.,0.,0,N_mom(lit,surrogateType_global_radial_basis)},
		{"recommended_points",8,0,3,0,0,0.,0.,0,N_mom(type,pointsManagement_RECOMMENDED_POINTS)},
		{"reuse_points",8,3,5,0,kw_1153},
		{"reuse_samples",0,3,5,0,kw_1153,0.,0.,-1},
		{"samples_file",3,4,6,0,kw_1131,0.,0.,-14,N_mom(str,importBuildPtsFile)},
		{"total_points",9,0,3,0,0,0.,0.,0,N_mom(int,pointsTotal)},
		{"truth_model_pointer",11,0,4,0,0,0.,0.,0,N_mom(str,truthModelPointer)},
		{"use_derivatives",8,0,8,0,0,0.,0.,0,N_mom(true,modelUseDerivsFlag)}
		},
	kw_1155[3] = {
		{"actual_model_pointer",3,0,2,2,0,0.,0.,2,N_mom(str,truthModelPointer)},
		{"taylor_series",8,0,1,1},
		{"truth_model_pointer",11,0,2,2,0,0.,0.,0,N_mom(str,truthModelPointer)}
		},
	kw_1156[4] = {
		{"actual_model_pointer",3,0,2,2,0,0.,0.,3,N_mom(str,truthModelPointer)},
		{"qmea",8,0,1,1,0,0.,0.,0,N_mom(lit,surrogateType_multipoint_qmea)},
		{"tana",8,0,1,1,0,0.,0.,0,N_mom(lit,surrogateType_multipoint_tana)},
		{"truth_model_pointer",11,0,2,2,0,0.,0.,0,N_mom(str,truthModelPointer)}
		},
	kw_1157[5] = {
		{"ensemble",8,4,2,1,kw_1087,0.,0.,0,N_mom(lit,surrogateType_ensemble)},
		{"global",8,31,2,1,kw_1154},
		{"id_surrogates",13,0,1,0,0,0.,0.,0,N_mom(id_to_index_set,surrogateFnIndices)},
		{"local",8,3,2,1,kw_1155,0.,0.,0,N_mom(lit,surrogateType_local_taylor)},
		{"multipoint",8,4,2,1,kw_1156}
		},
	kw_1158[12] = {
		{"active_subspace",8,9,2,1,kw_1070,0.,0.,0,N_mom(lit,modelType_active_subspace)},
		{"adapted_basis",8,3,2,1,kw_1074,0.,0.,0,N_mom(lit,modelType_adapted_basis)},
		{"hierarchical_tagging",8,0,5,0,0,0.,0.,0,N_mom(true,hierarchicalTags)},
		{"id_model",11,0,1,0,0,0.,0.,0,N_mom(str,idModel)},
		{"nested",8,2,2,1,kw_1078,0.,0.,0,N_mom(lit,modelType_nested)},
		{"random_field",8,5,2,1,kw_1082,0.,0.,0,N_mom(lit,modelType_random_field)},
		{"responses_pointer",11,0,4,0,0,0.,0.,0,N_mom(str,responsesPointer)},
		{"simulation",0,4,2,1,kw_1083,0.,0.,1,N_mom(lit,modelType_simulation)},
		{"single",8,4,2,1,kw_1083,0.,0.,0,N_mom(lit,modelType_simulation)},
		{"subspace",0,9,2,1,kw_1070,0.,0.,-9,N_mom(lit,modelType_active_subspace)},
		{"surrogate",8,5,2,1,kw_1157,0.,0.,0,N_mom(lit,modelType_surrogate)},
		{"variables_pointer",11,0,3,0,0,0.,0.,0,N_mom(str,variablesPointer)}
		},
	kw_1159[2] = {
		{"exp_id",8,0,2,0,0,0.,0.,0,N_rem(augment_utype,scalarDataFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_rem(augment_utype,scalarDataFormat_TABULAR_HEADER)}
		},
	kw_1160[3] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_rem(utype,scalarDataFormat_TABULAR_EXPER_ANNOT)},
		{"custom_annotated",8,2,1,0,kw_1159,0.,0.,0,N_rem(utype,scalarDataFormat_TABULAR_NONE)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_rem(utype,scalarDataFormat_TABULAR_NONE)}
		},
	kw_1161[7] = {
		{"data_directory",11,0,1,0,0,0.,0.,0,N_rem(str,dataPathPrefix)},
		{"experiment_variance_type",0x80f,0,4,0,0,0.,0.,0,N_rem(strL,varianceType)},
		{"interpolate",8,0,6,0,0,0.,0.,0,N_rem(true,interpolateFlag)},
		{"num_config_variables",0x29,0,3,0,0,0.,0.,0,N_rem(sizet,numExpConfigVars)},
		{"num_experiments",0x29,0,2,0,0,0.,0.,0,N_rem(sizet,numExperiments)},
		{"scalar_data_file",11,3,5,0,kw_1160,0.,0.,0,N_rem(str,scalarDataFileName)},
		{"variance_type",0x807,0,4,0,0,0.,0.,-5,N_rem(strL,varianceType)}
		},
	kw_1162[2] = {
		{"exp_id",8,0,2,0,0,0.,0.,0,N_rem(augment_utype,scalarDataFormat_TABULAR_EVAL_ID)},
		{"header",8,0,1,0,0,0.,0.,0,N_rem(augment_utype,scalarDataFormat_TABULAR_HEADER)}
		},
	kw_1163[7] = {
		{"annotated",8,0,1,0,0,0.,0.,0,N_rem(utype,scalarDataFormat_TABULAR_EXPER_ANNOT)},
		{"custom_annotated",8,2,1,0,kw_1162,0.,0.,0,N_rem(utype,scalarDataFormat_TABULAR_NONE)},
		{"experiment_variance_type",0x80f,0,4,0,0,0.,0.,0,N_rem(strL,varianceType)},
		{"freeform",8,0,1,0,0,0.,0.,0,N_rem(utype,scalarDataFormat_TABULAR_NONE)},
		{"num_config_variables",0x29,0,3,0,0,0.,0.,0,N_rem(sizet,numExpConfigVars)},
		{"num_experiments",0x29,0,2,0,0,0.,0.,0,N_rem(sizet,numExperiments)},
		{"variance_type",0x807,0,4,0,0,0.,0.,-4,N_rem(strL,varianceType)}
		},
	kw_1164[3] = {
		{"lengths",13,0,1,1,0,0.,0.,0,N_rem(ivec,fieldLengths)},
		{"num_coordinates_per_field",13,0,2,0,0,0.,0.,0,N_rem(ivec,numCoordsPerField)},
		{"read_field_coordinates",8,0,3,0,0,0.,0.,0,N_rem(true,readFieldCoords)}
		},
	kw_1165[6] = {
		{"nonlinear_equality_scale_types",0x807,0,2,0,0,0.,0.,3,N_rem(strL,nonlinearEqScaleTypes)},
		{"nonlinear_equality_scales",0x806,0,3,0,0,0.,0.,3,N_rem(RealDL,nonlinearEqScales)},
		{"nonlinear_equality_targets",6,0,1,0,0,0.,0.,3,N_rem(RealDL,nonlinearEqTargets)},
		{"scale_types",0x80f,0,2,0,0,0.,0.,0,N_rem(strL,nonlinearEqScaleTypes)},
		{"scales",0x80e,0,3,0,0,0.,0.,0,N_rem(RealDL,nonlinearEqScales)},
		{"targets",14,0,1,0,0,0.,0.,0,N_rem(RealDL,nonlinearEqTargets)}
		},
	kw_1166[8] = {
		{"lower_bounds",14,0,1,0,0,0.,0.,0,N_rem(RealDL,nonlinearIneqLowerBnds)},
		{"nonlinear_inequality_lower_bounds",6,0,1,0,0,0.,0.,-1,N_rem(RealDL,nonlinearIneqLowerBnds)},
		{"nonlinear_inequality_scale_types",0x807,0,3,0,0,0.,0.,3,N_rem(strL,nonlinearIneqScaleTypes)},
		{"nonlinear_inequality_scales",0x806,0,4,0,0,0.,0.,3,N_rem(RealDL,nonlinearIneqScales)},
		{"nonlinear_inequality_upper_bounds",6,0,2,0,0,0.,0.,3,N_rem(RealDL,nonlinearIneqUpperBnds)},
		{"scale_types",0x80f,0,3,0,0,0.,0.,0,N_rem(strL,nonlinearIneqScaleTypes)},
		{"scales",0x80e,0,4,0,0,0.,0.,0,N_rem(RealDL,nonlinearIneqScales)},
		{"upper_bounds",14,0,2,0,0,0.,0.,0,N_rem(RealDL,nonlinearIneqUpperBnds)}
		},
	kw_1167[16] = {
		{"calibration_data",8,7,5,0,kw_1161,0.,0.,0,N_rem(true,calibrationDataFlag)},
		{"calibration_data_file",11,7,5,0,kw_1163,0.,0.,0,N_rem(str,scalarDataFileName)},
		{"calibration_term_scales",6,0,3,0,0,0.,0.,10,N_rem(RealDL,primaryRespFnScales)},
		{"calibration_weights",6,0,4,0,0,0.,0.,12,N_rem(RealDL,primaryRespFnWeights)},
		{"field_calibration_terms",0x29,3,2,0,kw_1164,0.,0.,0,N_rem(sizet,numFieldLeastSqTerms)},
		{"least_squares_data_file",3,7,5,0,kw_1163,0.,0.,-4,N_rem(str,scalarDataFileName)},
		{"least_squares_term_scales",6,0,3,0,0,0.,0.,6,N_rem(RealDL,primaryRespFnScales)},
		{"least_squares_weights",6,0,4,0,0,0.,0.,8,N_rem(RealDL,primaryRespFnWeights)},
		{"nonlinear_equality_constraints",0x29,6,8,0,kw_1165,0.,0.,0,N_rem(sizet,numNonlinearEqConstraints)},
		{"nonlinear_inequality_constraints",0x29,8,7,0,kw_1166,0.,0.,0,N_rem(sizet,numNonlinearIneqConstraints)},
		{"num_nonlinear_equality_constraints",0x21,6,8,0,kw_1165,0.,0.,-2,N_rem(sizet,numNonlinearEqConstraints)},
		{"num_nonlinear_inequality_constraints",0x21,8,7,0,kw_1166,0.,0.,-2,N_rem(sizet,numNonlinearIneqConstraints)},
		{"primary_scales",14,0,3,0,0,0.,0.,0,N_rem(RealDL,primaryRespFnScales)},
		{"scalar_calibration_terms",0x29,0,1,0,0,0.,0.,0,N_rem(sizet,numScalarLeastSqTerms)},
		{"simulation_variance",0x80e,0,6,0,0,0.,0.,0,N_rem(RealL,simVariance)},
		{"weights",14,0,4,0,0,0.,0.,0,N_rem(RealDL,primaryRespFnWeights)}
		},
	kw_1168[4] = {
		{"absolute",8,0,2,0,0,0.,0.,0,N_rem(lit,fdGradStepType_absolute)},
		{"bounds",8,0,2,0,0,0.,0.,0,N_rem(lit,fdGradStepType_bounds)},
		{"ignore_bounds",8,0,1,0,0,0.,0.,0,N_rem(true,ignoreBounds)},
		{"relative",8,0,2,0,0,0.,0.,0,N_rem(lit,fdGradStepType_relative)}
		},
	kw_1169[10] = {
		{"central",8,0,6,0,0,0.,0.,0,N_rem(lit,intervalType_central)},
		{"dakota",8,4,4,0,kw_1168,0.,0.,0,N_rem(lit,methodSource_dakota)},
		{"fd_gradient_step_size",6,0,7,0,0,0.,0.,1,N_rem(RealL,fdGradStepSize)},
		{"fd_step_size",14,0,7,0,0,0.,0.,0,N_rem(RealL,fdGradStepSize)},
		{"forward",8,0,6,0,0,0.,0.,0,N_rem(lit,intervalType_forward)},
		{"id_analytic_gradients",13,0,2,2,0,0.,0.,0,N_rem(intset,idAnalyticGrads)},
		{"id_numerical_gradients",13,0,1,1,0,0.,0.,0,N_rem(intset,idNumericalGrads)},
		{"interval_type",8,0,5},
		{"method_source",8,0,3},
		{"vendor",8,0,4,0,0,0.,0.,0,N_rem(lit,methodSource_vendor)}
		},
	kw_1170[2] = {
		{"fd_hessian_step_size",6,0,1,0,0,0.,0.,1,N_rem(RealL,fdHessStepSize)},
		{"fd_step_size",14,0,1,0,0,0.,0.,0,N_rem(RealL,fdHessStepSize)}
		},
	kw_1171[1] = {
		{"damped",8,0,1,0,0,0.,0.,0,N_rem(lit,quasiHessianType_damped_bfgs)}
		},
	kw_1172[2] = {
		{"bfgs",8,1,1,1,kw_1171,0.,0.,0,N_rem(lit,quasiHessianType_bfgs)},
		{"sr1",8,0,1,1,0,0.,0.,0,N_rem(lit,quasiHessianType_sr1)}
		},
	kw_1173[8] = {
		{"absolute",8,0,2,0,0,0.,0.,0,N_rem(lit,fdHessStepType_absolute)},
		{"bounds",8,0,2,0,0,0.,0.,0,N_rem(lit,fdHessStepType_bounds)},
		{"central",8,0,3,0,0,0.,0.,0,N_rem(true,centralHess)},
		{"forward",8,0,3,0,0,0.,0.,0,N_rem(false,centralHess)},
		{"id_analytic_hessians",13,0,5,0,0,0.,0.,0,N_rem(intset,idAnalyticHessians)},
		{"id_numerical_hessians",13,2,1,0,kw_1170,0.,0.,0,N_rem(intset,idNumericalHessians)},
		{"id_quasi_hessians",13,2,4,0,kw_1172,0.,0.,0,N_rem(intset,idQuasiHessians)},
		{"relative",8,0,2,0,0,0.,0.,0,N_rem(lit,fdHessStepType_relative)}
		},
	kw_1174[3] = {
		{"lengths",13,0,1,1,0,0.,0.,0,N_rem(ivec,fieldLengths)},
		{"num_coordinates_per_field",13,0,2,0,0,0.,0.,0,N_rem(ivec,numCoordsPerField)},
		{"read_field_coordinates",8,0,3,0,0,0.,0.,0,N_rem(true,readFieldCoords)}
		},
	kw_1175[6] = {
		{"nonlinear_equality_scale_types",0x807,0,2,0,0,0.,0.,3,N_rem(strL,nonlinearEqScaleTypes)},
		{"nonlinear_equality_scales",0x806,0,3,0,0,0.,0.,3,N_rem(RealDL,nonlinearEqScales)},
		{"nonlinear_equality_targets",6,0,1,0,0,0.,0.,3,N_rem(RealDL,nonlinearEqTargets)},
		{"scale_types",0x80f,0,2,0,0,0.,0.,0,N_rem(strL,nonlinearEqScaleTypes)},
		{"scales",0x80e,0,3,0,0,0.,0.,0,N_rem(RealDL,nonlinearEqScales)},
		{"targets",14,0,1,0,0,0.,0.,0,N_rem(RealDL,nonlinearEqTargets)}
		},
	kw_1176[8] = {
		{"lower_bounds",14,0,1,0,0,0.,0.,0,N_rem(RealDL,nonlinearIneqLowerBnds)},
		{"nonlinear_inequality_lower_bounds",6,0,1,0,0,0.,0.,-1,N_rem(RealDL,nonlinearIneqLowerBnds)},
		{"nonlinear_inequality_scale_types",0x807,0,3,0,0,0.,0.,3,N_rem(strL,nonlinearIneqScaleTypes)},
		{"nonlinear_inequality_scales",0x806,0,4,0,0,0.,0.,3,N_rem(RealDL,nonlinearIneqScales)},
		{"nonlinear_inequality_upper_bounds",6,0,2,0,0,0.,0.,3,N_rem(RealDL,nonlinearIneqUpperBnds)},
		{"scale_types",0x80f,0,3,0,0,0.,0.,0,N_rem(strL,nonlinearIneqScaleTypes)},
		{"scales",0x80e,0,4,0,0,0.,0.,0,N_rem(RealDL,nonlinearIneqScales)},
		{"upper_bounds",14,0,2,0,0,0.,0.,0,N_rem(RealDL,nonlinearIneqUpperBnds)}
		},
	kw_1177[15] = {
		{"field_objectives",0x29,3,8,0,kw_1174,0.,0.,0,N_rem(sizet,numFieldObjectiveFunctions)},
		{"multi_objective_weights",6,0,4,0,0,0.,0.,13,N_rem(RealDL,primaryRespFnWeights)},
		{"nonlinear_equality_constraints",0x29,6,6,0,kw_1175,0.,0.,0,N_rem(sizet,numNonlinearEqConstraints)},
		{"nonlinear_inequality_constraints",0x29,8,5,0,kw_1176,0.,0.,0,N_rem(sizet,numNonlinearIneqConstraints)},
		{"num_field_objectives",0x21,3,8,0,kw_1174,0.,0.,-4,N_rem(sizet,numFieldObjectiveFunctions)},
		{"num_nonlinear_equality_constraints",0x21,6,6,0,kw_1175,0.,0.,-3,N_rem(sizet,numNonlinearEqConstraints)},
		{"num_nonlinear_inequality_constraints",0x21,8,5,0,kw_1176,0.,0.,-3,N_rem(sizet,numNonlinearIneqConstraints)},
		{"num_scalar_objectives",0x21,0,7,0,0,0.,0.,5,N_rem(sizet,numScalarObjectiveFunctions)},
		{"objective_function_scale_types",0x807,0,2,0,0,0.,0.,2,N_rem(strL,primaryRespFnScaleTypes)},
		{"objective_function_scales",6,0,3,0,0,0.,0.,2,N_rem(RealDL,primaryRespFnScales)},
		{"primary_scale_types",0x80f,0,2,0,0,0.,0.,0,N_rem(strL,primaryRespFnScaleTypes)},
		{"primary_scales",14,0,3,0,0,0.,0.,0,N_rem(RealDL,primaryRespFnScales)},
		{"scalar_objectives",0x29,0,7,0,0,0.,0.,0,N_rem(sizet,numScalarObjectiveFunctions)},
		{"sense",0x80f,0,1,0,0,0.,0.,0,N_rem(strL,primaryRespFnSense)},
		{"weights",14,0,4,0,0,0.,0.,0,N_rem(RealDL,primaryRespFnWeights)}
		},
	kw_1178[3] = {
		{"lengths",13,0,1,1,0,0.,0.,0,N_rem(ivec,fieldLengths)},
		{"num_coordinates_per_field",13,0,2,0,0,0.,0.,0,N_rem(ivec,numCoordsPerField)},
		{"read_field_coordinates",8,0,3,0,0,0.,0.,0,N_rem(true,readFieldCoords)}
		},
	kw_1179[4] = {
		{"field_responses",0x29,3,2,0,kw_1178,0.,0.,0,N_rem(sizet,numFieldResponseFunctions)},
		{"num_field_responses",0x21,3,2,0,kw_1178,0.,0.,-1,N_rem(sizet,numFieldResponseFunctions)},
		{"num_scalar_responses",0x21,0,1,0,0,0.,0.,1,N_rem(sizet,numScalarResponseFunctions)},
		{"scalar_responses",0x29,0,1,0,0,0.,0.,0,N_rem(sizet,numScalarResponseFunctions)}
		},
	kw_1180[4] = {
		{"absolute",8,0,2,0,0,0.,0.,0,N_rem(lit,fdGradStepType_absolute)},
		{"bounds",8,0,2,0,0,0.,0.,0,N_rem(lit,fdGradStepType_bounds)},
		{"ignore_bounds",8,0,1,0,0,0.,0.,0,N_rem(true,ignoreBounds)},
		{"relative",8,0,2,0,0,0.,0.,0,N_rem(lit,fdGradStepType_relative)}
		},
	kw_1181[8] = {
		{"central",8,0,4,0,0,0.,0.,0,N_rem(lit,intervalType_central)},
		{"dakota",8,4,2,0,kw_1180,0.,0.,0,N_rem(lit,methodSource_dakota)},
		{"fd_gradient_step_size",6,0,5,0,0,0.,0.,1,N_rem(RealL,fdGradStepSize)},
		{"fd_step_size",14,0,5,0,0,0.,0.,0,N_rem(RealL,fdGradStepSize)},
		{"forward",8,0,4,0,0,0.,0.,0,N_rem(lit,intervalType_forward)},
		{"interval_type",8,0,3},
		{"method_source",8,0,1},
		{"vendor",8,0,2,0,0,0.,0.,0,N_rem(lit,methodSource_vendor)}
		},
	kw_1182[7] = {
		{"absolute",8,0,2,0,0,0.,0.,0,N_rem(lit,fdHessStepType_absolute)},
		{"bounds",8,0,2,0,0,0.,0.,0,N_rem(lit,fdHessStepType_bounds)},
		{"central",8,0,3,0,0,0.,0.,0,N_rem(true,centralHess)},
		{"fd_hessian_step_size",6,0,1,0,0,0.,0.,1,N_rem(RealL,fdHessStepSize)},
		{"fd_step_size",14,0,1,0,0,0.,0.,0,N_rem(RealL,fdHessStepSize)},
		{"forward",8,0,3,0,0,0.,0.,0,N_rem(false,centralHess)},
		{"relative",8,0,2,0,0,0.,0.,0,N_rem(lit,fdHessStepType_relative)}
		},
	kw_1183[1] = {
		{"damped",8,0,1,0,0,0.,0.,0,N_rem(lit,quasiHessianType_damped_bfgs)}
		},
	kw_1184[2] = {
		{"bfgs",8,1,1,1,kw_1183,0.,0.,0,N_rem(lit,quasiHessianType_bfgs)},
		{"sr1",8,0,1,1,0,0.,0.,0,N_rem(lit,quasiHessianType_sr1)}
		},
	kw_1185[20] = {
		{"analytic_gradients",8,0,4,2,0,0.,0.,0,N_rem(lit,gradientType_analytic)},
		{"analytic_hessians",8,0,5,3,0,0.,0.,0,N_rem(lit,hessianType_analytic)},
		{"calibration_terms",0x29,16,3,1,kw_1167,0.,0.,0,N_rem(sizet,numLeastSqTerms)},
		{"descriptors",15,0,2,0,0,0.,0.,0,N_rem(strL,responseLabels)},
		{"id_responses",11,0,1,0,0,0.,0.,0,N_rem(str,idResponses)},
		{"least_squares_terms",0x21,16,3,1,kw_1167,0.,0.,-3,N_rem(sizet,numLeastSqTerms)},
		{"metadata",15,0,6,0,0,0.,0.,0,N_rem(strL,metadataLabels)},
		{"mixed_gradients",8,10,4,2,kw_1169,0.,0.,0,N_rem(lit,gradientType_mixed)},
		{"mixed_hessians",8,8,5,3,kw_1173,0.,0.,0,N_rem(lit,hessianType_mixed)},
		{"no_gradients",8,0,4,2,0,0.,0.,0,N_rem(lit,gradientType_none)},
		{"no_hessians",8,0,5,3,0,0.,0.,0,N_rem(lit,hessianType_none)},
		{"num_least_squares_terms",0x21,16,3,1,kw_1167,0.,0.,-9,N_rem(sizet,numLeastSqTerms)},
		{"num_objective_functions",0x21,15,3,1,kw_1177,0.,0.,4,N_rem(sizet,numObjectiveFunctions)},
		{"num_response_functions",0x21,4,3,1,kw_1179,0.,0.,6,N_rem(sizet,numResponseFunctions)},
		{"numerical_gradients",8,8,4,2,kw_1181,0.,0.,0,N_rem(lit,gradientType_numerical)},
		{"numerical_hessians",8,7,5,3,kw_1182,0.,0.,0,N_rem(lit,hessianType_numerical)},
		{"objective_functions",0x29,15,3,1,kw_1177,0.,0.,0,N_rem(sizet,numObjectiveFunctions)},
		{"quasi_hessians",8,2,5,3,kw_1184,0.,0.,0,N_rem(lit,hessianType_quasi)},
		{"response_descriptors",7,0,2,0,0,0.,0.,-15,N_rem(strL,responseLabels)},
		{"response_functions",0x29,4,3,1,kw_1179,0.,0.,0,N_rem(sizet,numResponseFunctions)}
		},
	kw_1186[6] = {
		{"aleatory",8,0,1,1,0,0.,0.,0,N_vam(type,varsView_ALEATORY_UNCERTAIN_VIEW)},
		{"all",8,0,1,1,0,0.,0.,0,N_vam(type,varsView_ALL_VIEW)},
		{"design",8,0,1,1,0,0.,0.,0,N_vam(type,varsView_DESIGN_VIEW)},
		{"epistemic",8,0,1,1,0,0.,0.,0,N_vam(type,varsView_EPISTEMIC_UNCERTAIN_VIEW)},
		{"state",8,0,1,1,0,0.,0.,0,N_vam(type,varsView_STATE_VIEW)},
		{"uncertain",8,0,1,1,0,0.,0.,0,N_vam(type,varsView_UNCERTAIN_VIEW)}
		},
	kw_1187[11] = {
		{"alphas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,betaUncAlphas)},
		{"betas",14,0,2,2,0,0.,0.,0,N_vam(RealLb,betaUncBetas)},
		{"buv_alphas",6,0,1,1,0,0.,0.,-2,N_vam(RealLb,betaUncAlphas)},
		{"buv_betas",6,0,2,2,0,0.,0.,-2,N_vam(RealLb,betaUncBetas)},
		{"buv_descriptors",7,0,6,0,0,0.,0.,3,N_vae(caulbl,CAUVar_beta)},
		{"buv_lower_bounds",6,0,3,3,0,0.,0.,4,N_vam(rvec,betaUncLowerBnds)},
		{"buv_upper_bounds",6,0,4,4,0,0.,0.,4,N_vam(rvec,betaUncUpperBnds)},
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vae(caulbl,CAUVar_beta)},
		{"initial_point",14,0,5,0,0,0.,0.,0,N_vam(rvec,betaUncVars)},
		{"lower_bounds",14,0,3,3,0,0.,0.,0,N_vam(rvec,betaUncLowerBnds)},
		{"upper_bounds",14,0,4,4,0,0.,0.,0,N_vam(rvec,betaUncUpperBnds)}
		},
	kw_1188[5] = {
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(dauilbl,DAUIVar_binomial)},
		{"initial_point",13,0,3,0,0,0.,0.,0,N_vam(IntLb,binomialUncVars)},
		{"num_trials",13,0,2,2,0,0.,0.,0,N_vam(IntLb,binomialUncNumTrials)},
		{"prob_per_trial",6,0,1,1,0,0.,0.,1,N_vam(rvec,binomialUncProbPerTrial)},
		{"probability_per_trial",14,0,1,1,0,0.,0.,0,N_vam(rvec,binomialUncProbPerTrial)}
		},
	kw_1189[12] = {
		{"cdv_descriptors",7,0,6,0,0,0.,0.,6,N_vam(strL,continuousDesignLabels)},
		{"cdv_initial_point",6,0,1,0,0,0.,0.,6,N_vam(rvec,continuousDesignVars)},
		{"cdv_lower_bounds",6,0,2,0,0,0.,0.,6,N_vam(rvec,continuousDesignLowerBnds)},
		{"cdv_scale_types",0x807,0,4,0,0,0.,0.,6,N_vam(strL,continuousDesignScaleTypes)},
		{"cdv_scales",0x806,0,5,0,0,0.,0.,6,N_vam(rvec,continuousDesignScales)},
		{"cdv_upper_bounds",6,0,3,0,0,0.,0.,6,N_vam(rvec,continuousDesignUpperBnds)},
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vam(strL,continuousDesignLabels)},
		{"initial_point",14,0,1,0,0,0.,0.,0,N_vam(rvec,continuousDesignVars)},
		{"lower_bounds",14,0,2,0,0,0.,0.,0,N_vam(rvec,continuousDesignLowerBnds)},
		{"scale_types",0x80f,0,4,0,0,0.,0.,0,N_vam(strL,continuousDesignScaleTypes)},
		{"scales",0x80e,0,5,0,0,0.,0.,0,N_vam(rvec,continuousDesignScales)},
		{"upper_bounds",14,0,3,0,0,0.,0.,0,N_vam(rvec,continuousDesignUpperBnds)}
		},
	kw_1190[10] = {
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vae(ceulbl,CEUVar_interval)},
		{"initial_point",14,0,5,0,0,0.,0.,0,N_vam(rvec,continuousIntervalUncVars)},
		{"interval_probabilities",14,0,2,0,0,0.,0.,0,N_vam(newrvec,Var_Info_CIp)},
		{"interval_probs",6,0,2,0,0,0.,0.,-1,N_vam(newrvec,Var_Info_CIp)},
		{"iuv_descriptors",7,0,6,0,0,0.,0.,-4,N_vae(ceulbl,CEUVar_interval)},
		{"iuv_interval_probs",6,0,2,0,0,0.,0.,-3,N_vam(newrvec,Var_Info_CIp)},
		{"iuv_num_intervals",5,0,1,0,0,0.,0.,2,N_vam(newiarray,Var_Info_nCI)},
		{"lower_bounds",14,0,3,1,0,0.,0.,0,N_vam(newrvec,Var_Info_CIlb)},
		{"num_intervals",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nCI)},
		{"upper_bounds",14,0,4,2,0,0.,0.,0,N_vam(newrvec,Var_Info_CIub)}
		},
	kw_1191[8] = {
		{"csv_descriptors",7,0,4,0,0,0.,0.,4,N_vam(strL,continuousStateLabels)},
		{"csv_initial_state",6,0,1,0,0,0.,0.,4,N_vam(rvec,continuousStateVars)},
		{"csv_lower_bounds",6,0,2,0,0,0.,0.,4,N_vam(rvec,continuousStateLowerBnds)},
		{"csv_upper_bounds",6,0,3,0,0,0.,0.,4,N_vam(rvec,continuousStateUpperBnds)},
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vam(strL,continuousStateLabels)},
		{"initial_state",14,0,1,0,0,0.,0.,0,N_vam(rvec,continuousStateVars)},
		{"lower_bounds",14,0,2,0,0,0.,0.,0,N_vam(rvec,continuousStateLowerBnds)},
		{"upper_bounds",14,0,3,0,0,0.,0.,0,N_vam(rvec,continuousStateUpperBnds)}
		},
	kw_1192[8] = {
		{"ddv_descriptors",7,0,4,0,0,0.,0.,4,N_vam(strL,discreteDesignRangeLabels)},
		{"ddv_initial_point",5,0,1,0,0,0.,0.,4,N_vam(ivec,discreteDesignRangeVars)},
		{"ddv_lower_bounds",5,0,2,0,0,0.,0.,4,N_vam(ivec,discreteDesignRangeLowerBnds)},
		{"ddv_upper_bounds",5,0,3,0,0,0.,0.,4,N_vam(ivec,discreteDesignRangeUpperBnds)},
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vam(strL,discreteDesignRangeLabels)},
		{"initial_point",13,0,1,0,0,0.,0.,0,N_vam(ivec,discreteDesignRangeVars)},
		{"lower_bounds",13,0,2,0,0,0.,0.,0,N_vam(ivec,discreteDesignRangeLowerBnds)},
		{"upper_bounds",13,0,3,0,0,0.,0.,0,N_vam(ivec,discreteDesignRangeUpperBnds)}
		},
	kw_1193[1] = {
		{"adjacency_matrix",13,0,1,0,0,0.,0.,0,N_vam(newivec,Var_Info_ddsia)}
		},
	kw_1194[7] = {
		{"categorical",15,1,3,0,kw_1193,0.,0.,0,N_vam(categorical,discreteDesignSetIntCat)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vam(strL,discreteDesignSetIntLabels)},
		{"elements",13,0,2,1,0,0.,0.,0,N_vam(newivec,Var_Info_ddsi)},
		{"elements_per_variable",0x80d,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nddsi)},
		{"initial_point",13,0,4,0,0,0.,0.,0,N_vam(ivec,discreteDesignSetIntVars)},
		{"num_set_values",0x805,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_nddsi)},
		{"set_values",5,0,2,1,0,0.,0.,-4,N_vam(newivec,Var_Info_ddsi)}
		},
	kw_1195[1] = {
		{"adjacency_matrix",13,0,1,0,0,0.,0.,0,N_vam(newivec,Var_Info_ddsra)}
		},
	kw_1196[7] = {
		{"categorical",15,1,3,0,kw_1195,0.,0.,0,N_vam(categorical,discreteDesignSetRealCat)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vam(strL,discreteDesignSetRealLabels)},
		{"elements",14,0,2,1,0,0.,0.,0,N_vam(newrvec,Var_Info_ddsr)},
		{"elements_per_variable",0x80d,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nddsr)},
		{"initial_point",14,0,4,0,0,0.,0.,0,N_vam(rvec,discreteDesignSetRealVars)},
		{"num_set_values",0x805,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_nddsr)},
		{"set_values",6,0,2,1,0,0.,0.,-4,N_vam(newrvec,Var_Info_ddsr)}
		},
	kw_1197[7] = {
		{"adjacency_matrix",13,0,3,0,0,0.,0.,0,N_vam(newivec,Var_Info_ddssa)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vam(strL,discreteDesignSetStrLabels)},
		{"elements",15,0,2,1,0,0.,0.,0,N_vam(newsarray,Var_Info_ddss)},
		{"elements_per_variable",0x80d,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nddss)},
		{"initial_point",15,0,4,0,0,0.,0.,0,N_vam(strL,discreteDesignSetStrVars)},
		{"num_set_values",0x805,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_nddss)},
		{"set_values",7,0,2,1,0,0.,0.,-4,N_vam(newsarray,Var_Info_ddss)}
		},
	kw_1198[3] = {
		{"integer",0x19,7,1,0,kw_1194,0.,0.,0,N_vam(sizet,numDiscreteDesSetIntVars)},
		{"real",0x19,7,3,0,kw_1196,0.,0.,0,N_vam(sizet,numDiscreteDesSetRealVars)},
		{"string",0x19,7,2,0,kw_1197,0.,0.,0,N_vam(sizet,numDiscreteDesSetStrVars)}
		},
	kw_1199[9] = {
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vae(deuilbl,DEUIVar_interval)},
		{"initial_point",13,0,5,0,0,0.,0.,0,N_vam(ivec,discreteIntervalUncVars)},
		{"interval_probabilities",14,0,2,0,0,0.,0.,0,N_vam(newrvec,Var_Info_DIp)},
		{"interval_probs",6,0,2,0,0,0.,0.,-1,N_vam(newrvec,Var_Info_DIp)},
		{"lower_bounds",13,0,3,1,0,0.,0.,0,N_vam(newivec,Var_Info_DIlb)},
		{"num_intervals",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nDI)},
		{"range_probabilities",6,0,2,0,0,0.,0.,-4,N_vam(newrvec,Var_Info_DIp)},
		{"range_probs",6,0,2,0,0,0.,0.,-5,N_vam(newrvec,Var_Info_DIp)},
		{"upper_bounds",13,0,4,2,0,0.,0.,0,N_vam(newivec,Var_Info_DIub)}
		},
	kw_1200[8] = {
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vam(strL,discreteStateRangeLabels)},
		{"dsv_descriptors",7,0,4,0,0,0.,0.,-1,N_vam(strL,discreteStateRangeLabels)},
		{"dsv_initial_state",5,0,1,0,0,0.,0.,3,N_vam(ivec,discreteStateRangeVars)},
		{"dsv_lower_bounds",5,0,2,0,0,0.,0.,3,N_vam(ivec,discreteStateRangeLowerBnds)},
		{"dsv_upper_bounds",5,0,3,0,0,0.,0.,3,N_vam(ivec,discreteStateRangeUpperBnds)},
		{"initial_state",13,0,1,0,0,0.,0.,0,N_vam(ivec,discreteStateRangeVars)},
		{"lower_bounds",13,0,2,0,0,0.,0.,0,N_vam(ivec,discreteStateRangeLowerBnds)},
		{"upper_bounds",13,0,3,0,0,0.,0.,0,N_vam(ivec,discreteStateRangeUpperBnds)}
		},
	kw_1201[7] = {
		{"categorical",15,0,3,0,0,0.,0.,0,N_vam(categorical,discreteStateSetIntCat)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vam(strL,discreteStateSetIntLabels)},
		{"elements",13,0,2,1,0,0.,0.,0,N_vam(newivec,Var_Info_dssi)},
		{"elements_per_variable",0x80d,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_ndssi)},
		{"initial_state",13,0,4,0,0,0.,0.,0,N_vam(ivec,discreteStateSetIntVars)},
		{"num_set_values",0x805,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_ndssi)},
		{"set_values",5,0,2,1,0,0.,0.,-4,N_vam(newivec,Var_Info_dssi)}
		},
	kw_1202[7] = {
		{"categorical",15,0,3,0,0,0.,0.,0,N_vam(categorical,discreteStateSetRealCat)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vam(strL,discreteStateSetRealLabels)},
		{"elements",14,0,2,1,0,0.,0.,0,N_vam(newrvec,Var_Info_dssr)},
		{"elements_per_variable",0x80d,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_ndssr)},
		{"initial_state",14,0,4,0,0,0.,0.,0,N_vam(rvec,discreteStateSetRealVars)},
		{"num_set_values",0x805,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_ndssr)},
		{"set_values",6,0,2,1,0,0.,0.,-4,N_vam(newrvec,Var_Info_dssr)}
		},
	kw_1203[6] = {
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vam(strL,discreteStateSetStrLabels)},
		{"elements",15,0,2,1,0,0.,0.,0,N_vam(newsarray,Var_Info_dsss)},
		{"elements_per_variable",0x80d,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_ndsss)},
		{"initial_state",15,0,3,0,0,0.,0.,0,N_vam(strL,discreteStateSetStrVars)},
		{"num_set_values",0x805,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_ndsss)},
		{"set_values",7,0,2,1,0,0.,0.,-4,N_vam(newsarray,Var_Info_dsss)}
		},
	kw_1204[3] = {
		{"integer",0x19,7,1,0,kw_1201,0.,0.,0,N_vam(sizet,numDiscreteStateSetIntVars)},
		{"real",0x19,7,3,0,kw_1202,0.,0.,0,N_vam(sizet,numDiscreteStateSetRealVars)},
		{"string",0x19,6,2,0,kw_1203,0.,0.,0,N_vam(sizet,numDiscreteStateSetStrVars)}
		},
	kw_1205[9] = {
		{"categorical",15,0,4,0,0,0.,0.,0,N_vam(categorical,discreteUncSetIntCat)},
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vae(deuilbl,DEUIVar_set_int)},
		{"elements",13,0,2,1,0,0.,0.,0,N_vam(newivec,Var_Info_dusi)},
		{"elements_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_ndusi)},
		{"initial_point",13,0,5,0,0,0.,0.,0,N_vam(ivec,discreteUncSetIntVars)},
		{"num_set_values",5,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_ndusi)},
		{"set_probabilities",14,0,3,0,0,0.,0.,0,N_vam(newrvec,Var_Info_DSIp)},
		{"set_probs",6,0,3,0,0,0.,0.,-1,N_vam(newrvec,Var_Info_DSIp)},
		{"set_values",5,0,2,1,0,0.,0.,-6,N_vam(newivec,Var_Info_dusi)}
		},
	kw_1206[9] = {
		{"categorical",15,0,4,0,0,0.,0.,0,N_vam(categorical,discreteUncSetRealCat)},
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vae(deurlbl,DEURVar_set_real)},
		{"elements",14,0,2,1,0,0.,0.,0,N_vam(newrvec,Var_Info_dusr)},
		{"elements_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_ndusr)},
		{"initial_point",14,0,5,0,0,0.,0.,0,N_vam(rvec,discreteUncSetRealVars)},
		{"num_set_values",5,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_ndusr)},
		{"set_probabilities",14,0,3,0,0,0.,0.,0,N_vam(newrvec,Var_Info_DSRp)},
		{"set_probs",6,0,3,0,0,0.,0.,-1,N_vam(newrvec,Var_Info_DSRp)},
		{"set_values",6,0,2,1,0,0.,0.,-6,N_vam(newrvec,Var_Info_dusr)}
		},
	kw_1207[8] = {
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(deuslbl,DEUSVar_set_str)},
		{"elements",15,0,2,1,0,0.,0.,0,N_vam(newsarray,Var_Info_duss)},
		{"elements_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nduss)},
		{"initial_point",15,0,4,0,0,0.,0.,0,N_vam(strL,discreteUncSetStrVars)},
		{"num_set_values",5,0,1,0,0,0.,0.,-2,N_vam(newiarray,Var_Info_nduss)},
		{"set_probabilities",14,0,3,0,0,0.,0.,0,N_vam(newrvec,Var_Info_DSSp)},
		{"set_probs",6,0,3,0,0,0.,0.,-1,N_vam(newrvec,Var_Info_DSSp)},
		{"set_values",7,0,2,1,0,0.,0.,-6,N_vam(newsarray,Var_Info_duss)}
		},
	kw_1208[3] = {
		{"integer",0x19,9,1,0,kw_1205,0.,0.,0,N_vam(sizet,numDiscreteUncSetIntVars)},
		{"real",0x19,9,3,0,kw_1206,0.,0.,0,N_vam(sizet,numDiscreteUncSetRealVars)},
		{"string",0x19,8,2,0,kw_1207,0.,0.,0,N_vam(sizet,numDiscreteUncSetStrVars)}
		},
	kw_1209[5] = {
		{"betas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,exponentialUncBetas)},
		{"descriptors",15,0,3,0,0,0.,0.,0,N_vae(caulbl,CAUVar_exponential)},
		{"euv_betas",6,0,1,1,0,0.,0.,-2,N_vam(RealLb,exponentialUncBetas)},
		{"euv_descriptors",7,0,3,0,0,0.,0.,-2,N_vae(caulbl,CAUVar_exponential)},
		{"initial_point",14,0,2,0,0,0.,0.,0,N_vam(RealLb,exponentialUncVars)}
		},
	kw_1210[7] = {
		{"alphas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,frechetUncAlphas)},
		{"betas",14,0,2,2,0,0.,0.,0,N_vam(rvec,frechetUncBetas)},
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(caulbl,CAUVar_frechet)},
		{"fuv_alphas",6,0,1,1,0,0.,0.,-3,N_vam(RealLb,frechetUncAlphas)},
		{"fuv_betas",6,0,2,2,0,0.,0.,-3,N_vam(rvec,frechetUncBetas)},
		{"fuv_descriptors",7,0,4,0,0,0.,0.,-3,N_vae(caulbl,CAUVar_frechet)},
		{"initial_point",14,0,3,0,0,0.,0.,0,N_vam(rvec,frechetUncVars)}
		},
	kw_1211[7] = {
		{"alphas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,gammaUncAlphas)},
		{"betas",14,0,2,2,0,0.,0.,0,N_vam(RealLb,gammaUncBetas)},
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(caulbl,CAUVar_gamma)},
		{"gauv_alphas",6,0,1,1,0,0.,0.,-3,N_vam(RealLb,gammaUncAlphas)},
		{"gauv_betas",6,0,2,2,0,0.,0.,-3,N_vam(RealLb,gammaUncBetas)},
		{"gauv_descriptors",7,0,4,0,0,0.,0.,-3,N_vae(caulbl,CAUVar_gamma)},
		{"initial_point",14,0,3,0,0,0.,0.,0,N_vam(RealLb,gammaUncVars)}
		},
	kw_1212[4] = {
		{"descriptors",15,0,3,0,0,0.,0.,0,N_vae(dauilbl,DAUIVar_geometric)},
		{"initial_point",13,0,2,0,0,0.,0.,0,N_vam(IntLb,geometricUncVars)},
		{"prob_per_trial",6,0,1,1,0,0.,0.,1,N_vam(rvec,geometricUncProbPerTrial)},
		{"probability_per_trial",14,0,1,1,0,0.,0.,0,N_vam(rvec,geometricUncProbPerTrial)}
		},
	kw_1213[7] = {
		{"alphas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,gumbelUncAlphas)},
		{"betas",14,0,2,2,0,0.,0.,0,N_vam(rvec,gumbelUncBetas)},
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(caulbl,CAUVar_gumbel)},
		{"guuv_alphas",6,0,1,1,0,0.,0.,-3,N_vam(RealLb,gumbelUncAlphas)},
		{"guuv_betas",6,0,2,2,0,0.,0.,-3,N_vam(rvec,gumbelUncBetas)},
		{"guuv_descriptors",7,0,4,0,0,0.,0.,-3,N_vae(caulbl,CAUVar_gumbel)},
		{"initial_point",14,0,3,0,0,0.,0.,0,N_vam(rvec,gumbelUncVars)}
		},
	kw_1214[11] = {
		{"abscissas",14,0,2,1,0,0.,0.,0,N_vam(newrvec,Var_Info_hba)},
		{"counts",14,0,3,2,0,0.,0.,0,N_vam(newrvec,Var_Info_hbc)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(caulbl,CAUVar_histogram_bin)},
		{"huv_bin_abscissas",6,0,2,1,0,0.,0.,-3,N_vam(newrvec,Var_Info_hba)},
		{"huv_bin_counts",6,0,3,2,0,0.,0.,-3,N_vam(newrvec,Var_Info_hbc)},
		{"huv_bin_descriptors",7,0,5,0,0,0.,0.,-3,N_vae(caulbl,CAUVar_histogram_bin)},
		{"huv_bin_ordinates",6,0,3,2,0,0.,0.,3,N_vam(newrvec,Var_Info_hbo)},
		{"initial_point",14,0,4,0,0,0.,0.,0,N_vam(rvec,histogramBinUncVars)},
		{"num_pairs",5,0,1,0,0,0.,0.,2,N_vam(newiarray,Var_Info_nhbp)},
		{"ordinates",14,0,3,2,0,0.,0.,0,N_vam(newrvec,Var_Info_hbo)},
		{"pairs_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nhbp)}
		},
	kw_1215[6] = {
		{"abscissas",13,0,2,1,0,0.,0.,0,N_vam(newivec,Var_Info_hpia)},
		{"counts",14,0,3,2,0,0.,0.,0,N_vam(newrvec,Var_Info_hpic)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(dauilbl,DAUIVar_histogram_point_int)},
		{"initial_point",13,0,4,0,0,0.,0.,0,N_vam(ivec,histogramPointIntUncVars)},
		{"num_pairs",5,0,1,0,0,0.,0.,1,N_vam(newiarray,Var_Info_nhpip)},
		{"pairs_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nhpip)}
		},
	kw_1216[6] = {
		{"abscissas",14,0,2,1,0,0.,0.,0,N_vam(newrvec,Var_Info_hpra)},
		{"counts",14,0,3,2,0,0.,0.,0,N_vam(newrvec,Var_Info_hprc)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(daurlbl,DAURVar_histogram_point_real)},
		{"initial_point",14,0,4,0,0,0.,0.,0,N_vam(rvec,histogramPointRealUncVars)},
		{"num_pairs",5,0,1,0,0,0.,0.,1,N_vam(newiarray,Var_Info_nhprp)},
		{"pairs_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nhprp)}
		},
	kw_1217[6] = {
		{"abscissas",15,0,2,1,0,0.,0.,0,N_vam(newsarray,Var_Info_hpsa)},
		{"counts",14,0,3,2,0,0.,0.,0,N_vam(newrvec,Var_Info_hpsc)},
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(dauslbl,DAUSVar_histogram_point_str)},
		{"initial_point",15,0,4,0,0,0.,0.,0,N_vam(strL,histogramPointStrUncVars)},
		{"num_pairs",5,0,1,0,0,0.,0.,1,N_vam(newiarray,Var_Info_nhpsp)},
		{"pairs_per_variable",13,0,1,0,0,0.,0.,0,N_vam(newiarray,Var_Info_nhpsp)}
		},
	kw_1218[3] = {
		{"integer",0x19,6,1,0,kw_1215,0.,0.,0,N_vam(sizet,numHistogramPtIntUncVars)},
		{"real",0x19,6,3,0,kw_1216,0.,0.,0,N_vam(sizet,numHistogramPtRealUncVars)},
		{"string",0x19,6,2,0,kw_1217,0.,0.,0,N_vam(sizet,numHistogramPtStrUncVars)}
		},
	kw_1219[5] = {
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(dauilbl,DAUIVar_hypergeometric)},
		{"initial_point",13,0,4,0,0,0.,0.,0,N_vam(IntLb,hyperGeomUncVars)},
		{"num_drawn",13,0,3,3,0,0.,0.,0,N_vam(IntLb,hyperGeomUncNumDrawn)},
		{"selected_population",13,0,2,2,0,0.,0.,0,N_vam(IntLb,hyperGeomUncSelectedPop)},
		{"total_population",13,0,1,1,0,0.,0.,0,N_vam(IntLb,hyperGeomUncTotalPop)}
		},
	kw_1220[2] = {
		{"lnuv_zetas",6,0,1,1,0,0.,0.,1,N_vam(RealLb,lognormalUncZetas)},
		{"zetas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,lognormalUncZetas)}
		},
	kw_1221[4] = {
		{"error_factors",14,0,1,1,0,0.,0.,0,N_vam(RealLb,lognormalUncErrFacts)},
		{"lnuv_error_factors",6,0,1,1,0,0.,0.,-1,N_vam(RealLb,lognormalUncErrFacts)},
		{"lnuv_std_deviations",6,0,1,1,0,0.,0.,1,N_vam(RealLb,lognormalUncStdDevs)},
		{"std_deviations",14,0,1,1,0,0.,0.,0,N_vam(RealLb,lognormalUncStdDevs)}
		},
	kw_1222[11] = {
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(caulbl,CAUVar_lognormal)},
		{"initial_point",14,0,4,0,0,0.,0.,0,N_vam(RealLb,lognormalUncVars)},
		{"lambdas",14,2,1,1,kw_1220,0.,0.,0,N_vam(rvec,lognormalUncLambdas)},
		{"lnuv_descriptors",7,0,5,0,0,0.,0.,-3,N_vae(caulbl,CAUVar_lognormal)},
		{"lnuv_lambdas",6,2,1,1,kw_1220,0.,0.,-2,N_vam(rvec,lognormalUncLambdas)},
		{"lnuv_lower_bounds",6,0,2,0,0,0.,0.,3,N_vam(RealLb,lognormalUncLowerBnds)},
		{"lnuv_means",6,4,1,1,kw_1221,0.,0.,3,N_vam(RealLb,lognormalUncMeans)},
		{"lnuv_upper_bounds",6,0,3,0,0,0.,0.,3,N_vam(RealUb,lognormalUncUpperBnds)},
		{"lower_bounds",14,0,2,0,0,0.,0.,0,N_vam(RealLb,lognormalUncLowerBnds)},
		{"means",14,4,1,1,kw_1221,0.,0.,0,N_vam(RealLb,lognormalUncMeans)},
		{"upper_bounds",14,0,3,0,0,0.,0.,0,N_vam(RealUb,lognormalUncUpperBnds)}
		},
	kw_1223[7] = {
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(caulbl,CAUVar_loguniform)},
		{"initial_point",14,0,3,0,0,0.,0.,0,N_vam(RealLb,loguniformUncVars)},
		{"lower_bounds",14,0,1,1,0,0.,0.,0,N_vam(RealLb,loguniformUncLowerBnds)},
		{"luuv_descriptors",7,0,4,0,0,0.,0.,-3,N_vae(caulbl,CAUVar_loguniform)},
		{"luuv_lower_bounds",6,0,1,1,0,0.,0.,-2,N_vam(RealLb,loguniformUncLowerBnds)},
		{"luuv_upper_bounds",6,0,2,2,0,0.,0.,1,N_vam(RealUb,loguniformUncUpperBnds)},
		{"upper_bounds",14,0,2,2,0,0.,0.,0,N_vam(RealUb,loguniformUncUpperBnds)}
		},
	kw_1224[5] = {
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(dauilbl,DAUIVar_negative_binomial)},
		{"initial_point",13,0,3,0,0,0.,0.,0,N_vam(IntLb,negBinomialUncVars)},
		{"num_trials",13,0,2,2,0,0.,0.,0,N_vam(IntLb,negBinomialUncNumTrials)},
		{"prob_per_trial",6,0,1,1,0,0.,0.,1,N_vam(rvec,negBinomialUncProbPerTrial)},
		{"probability_per_trial",14,0,1,1,0,0.,0.,0,N_vam(rvec,negBinomialUncProbPerTrial)}
		},
	kw_1225[11] = {
		{"descriptors",15,0,6,0,0,0.,0.,0,N_vae(caulbl,CAUVar_normal)},
		{"initial_point",14,0,5,0,0,0.,0.,0,N_vam(rvec,normalUncVars)},
		{"lower_bounds",14,0,3,0,0,0.,0.,0,N_vam(rvec,normalUncLowerBnds)},
		{"means",14,0,1,1,0,0.,0.,0,N_vam(rvec,normalUncMeans)},
		{"nuv_descriptors",7,0,6,0,0,0.,0.,-4,N_vae(caulbl,CAUVar_normal)},
		{"nuv_lower_bounds",6,0,3,0,0,0.,0.,-3,N_vam(rvec,normalUncLowerBnds)},
		{"nuv_means",6,0,1,1,0,0.,0.,-3,N_vam(rvec,normalUncMeans)},
		{"nuv_std_deviations",6,0,2,2,0,0.,0.,2,N_vam(RealLb,normalUncStdDevs)},
		{"nuv_upper_bounds",6,0,4,0,0,0.,0.,2,N_vam(rvec,normalUncUpperBnds)},
		{"std_deviations",14,0,2,2,0,0.,0.,0,N_vam(RealLb,normalUncStdDevs)},
		{"upper_bounds",14,0,4,0,0,0.,0.,0,N_vam(rvec,normalUncUpperBnds)}
		},
	kw_1226[3] = {
		{"descriptors",15,0,3,0,0,0.,0.,0,N_vae(dauilbl,DAUIVar_poisson)},
		{"initial_point",13,0,2,0,0,0.,0.,0,N_vam(IntLb,poissonUncVars)},
		{"lambdas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,poissonUncLambdas)}
		},
	kw_1227[9] = {
		{"descriptors",15,0,5,0,0,0.,0.,0,N_vae(caulbl,CAUVar_triangular)},
		{"initial_point",14,0,4,0,0,0.,0.,0,N_vam(rvec,triangularUncVars)},
		{"lower_bounds",14,0,2,2,0,0.,0.,0,N_vam(RealLb,triangularUncLowerBnds)},
		{"modes",14,0,1,1,0,0.,0.,0,N_vam(rvec,triangularUncModes)},
		{"tuv_descriptors",7,0,5,0,0,0.,0.,-4,N_vae(caulbl,CAUVar_triangular)},
		{"tuv_lower_bounds",6,0,2,2,0,0.,0.,-3,N_vam(RealLb,triangularUncLowerBnds)},
		{"tuv_modes",6,0,1,1,0,0.,0.,-3,N_vam(rvec,triangularUncModes)},
		{"tuv_upper_bounds",6,0,3,3,0,0.,0.,1,N_vam(RealUb,triangularUncUpperBnds)},
		{"upper_bounds",14,0,3,3,0,0.,0.,0,N_vam(RealUb,triangularUncUpperBnds)}
		},
	kw_1228[7] = {
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(caulbl,CAUVar_uniform)},
		{"initial_point",14,0,3,0,0,0.,0.,0,N_vam(rvec,uniformUncVars)},
		{"lower_bounds",14,0,1,1,0,0.,0.,0,N_vam(RealLb,uniformUncLowerBnds)},
		{"upper_bounds",14,0,2,2,0,0.,0.,0,N_vam(RealUb,uniformUncUpperBnds)},
		{"uuv_descriptors",7,0,4,0,0,0.,0.,-4,N_vae(caulbl,CAUVar_uniform)},
		{"uuv_lower_bounds",6,0,1,1,0,0.,0.,-3,N_vam(RealLb,uniformUncLowerBnds)},
		{"uuv_upper_bounds",6,0,2,2,0,0.,0.,-3,N_vam(RealUb,uniformUncUpperBnds)}
		},
	kw_1229[7] = {
		{"alphas",14,0,1,1,0,0.,0.,0,N_vam(RealLb,weibullUncAlphas)},
		{"betas",14,0,2,2,0,0.,0.,0,N_vam(RealLb,weibullUncBetas)},
		{"descriptors",15,0,4,0,0,0.,0.,0,N_vae(caulbl,CAUVar_weibull)},
		{"initial_point",14,0,3,0,0,0.,0.,0,N_vam(RealLb,weibullUncVars)},
		{"wuv_alphas",6,0,1,1,0,0.,0.,-4,N_vam(RealLb,weibullUncAlphas)},
		{"wuv_betas",6,0,2,2,0,0.,0.,-4,N_vam(RealLb,weibullUncBetas)},
		{"wuv_descriptors",7,0,4,0,0,0.,0.,-4,N_vae(caulbl,CAUVar_weibull)}
		},
	kw_1230[42] = {
		{"active",8,6,2,0,kw_1186},
		{"beta_uncertain",0x19,11,13,0,kw_1187,0.,0.,0,N_vam(sizet,numBetaUncVars)},
		{"binomial_uncertain",0x19,5,20,0,kw_1188,0.,0.,0,N_vam(sizet,numBinomialUncVars)},
		{"continuous_design",0x19,12,4,0,kw_1189,0.,0.,0,N_vam(sizet,numContinuousDesVars)},
		{"continuous_interval_uncertain",0x19,10,26,0,kw_1190,0.,0.,0,N_vam(sizet,numContinuousIntervalUncVars)},
		{"continuous_state",0x19,8,29,0,kw_1191,0.,0.,0,N_vam(sizet,numContinuousStateVars)},
		{"discrete_design_range",0x19,8,5,0,kw_1192,0.,0.,0,N_vam(sizet,numDiscreteDesRangeVars)},
		{"discrete_design_set",8,3,6,0,kw_1198},
		{"discrete_interval_uncertain",0x19,9,27,0,kw_1199,0.,0.,0,N_vam(sizet,numDiscreteIntervalUncVars)},
		{"discrete_state_range",0x19,8,30,0,kw_1200,0.,0.,0,N_vam(sizet,numDiscreteStateRangeVars)},
		{"discrete_state_set",8,3,31,0,kw_1204},
		{"discrete_uncertain_set",8,3,28,0,kw_1208},
		{"exponential_uncertain",0x19,5,12,0,kw_1209,0.,0.,0,N_vam(sizet,numExponentialUncVars)},
		{"frechet_uncertain",0x19,7,16,0,kw_1210,0.,0.,0,N_vam(sizet,numFrechetUncVars)},
		{"gamma_uncertain",0x19,7,14,0,kw_1211,0.,0.,0,N_vam(sizet,numGammaUncVars)},
		{"geometric_uncertain",0x19,4,22,0,kw_1212,0.,0.,0,N_vam(sizet,numGeometricUncVars)},
		{"gumbel_uncertain",0x19,7,15,0,kw_1213,0.,0.,0,N_vam(sizet,numGumbelUncVars)},
		{"histogram_bin_uncertain",0x19,11,18,0,kw_1214,0.,0.,0,N_vam(sizet,numHistogramBinUncVars)},
		{"histogram_point_uncertain",8,3,24,0,kw_1218},
		{"hypergeometric_uncertain",0x19,5,23,0,kw_1219,0.,0.,0,N_vam(sizet,numHyperGeomUncVars)},
		{"id_variables",11,0,1,0,0,0.,0.,0,N_vam(str,idVariables)},
		{"interval_uncertain",0x11,10,26,0,kw_1190,0.,0.,-17,N_vam(sizet,numContinuousIntervalUncVars)},
		{"linear_equality_constraint_matrix",14,0,37,0,0,0.,0.,0,N_vam(rvec,linearEqConstraintCoeffs)},
		{"linear_equality_scale_types",15,0,39,0,0,0.,0.,0,N_vam(strL,linearEqScaleTypes)},
		{"linear_equality_scales",14,0,40,0,0,0.,0.,0,N_vam(rvec,linearEqScales)},
		{"linear_equality_targets",14,0,38,0,0,0.,0.,0,N_vam(rvec,linearEqTargets)},
		{"linear_inequality_constraint_matrix",14,0,32,0,0,0.,0.,0,N_vam(rvec,linearIneqConstraintCoeffs)},
		{"linear_inequality_lower_bounds",14,0,33,0,0,0.,0.,0,N_vam(rvec,linearIneqLowerBnds)},
		{"linear_inequality_scale_types",15,0,35,0,0,0.,0.,0,N_vam(strL,linearIneqScaleTypes)},
		{"linear_inequality_scales",14,0,36,0,0,0.,0.,0,N_vam(rvec,linearIneqScales)},
		{"linear_inequality_upper_bounds",14,0,34,0,0,0.,0.,0,N_vam(rvec,linearIneqUpperBnds)},
		{"lognormal_uncertain",0x19,11,8,0,kw_1222,0.,0.,0,N_vam(sizet,numLognormalUncVars)},
		{"loguniform_uncertain",0x19,7,10,0,kw_1223,0.,0.,0,N_vam(sizet,numLoguniformUncVars)},
		{"mixed",8,0,3,0,0,0.,0.,0,N_vam(type,varsDomain_MIXED_DOMAIN)},
		{"negative_binomial_uncertain",0x19,5,21,0,kw_1224,0.,0.,0,N_vam(sizet,numNegBinomialUncVars)},
		{"normal_uncertain",0x19,11,7,0,kw_1225,0.,0.,0,N_vam(sizet,numNormalUncVars)},
		{"poisson_uncertain",0x19,3,19,0,kw_1226,0.,0.,0,N_vam(sizet,numPoissonUncVars)},
		{"relaxed",8,0,3,0,0,0.,0.,0,N_vam(type,varsDomain_RELAXED_DOMAIN)},
		{"triangular_uncertain",0x19,9,11,0,kw_1227,0.,0.,0,N_vam(sizet,numTriangularUncVars)},
		{"uncertain_correlation_matrix",14,0,25,0,0,0.,0.,0,N_vam(newrvec,Var_Info_ucm)},
		{"uniform_uncertain",0x19,7,9,0,kw_1228,0.,0.,0,N_vam(sizet,numUniformUncVars)},
		{"weibull_uncertain",0x19,7,17,0,kw_1229,0.,0.,0,N_vam(sizet,numWeibullUncVars)}
		},
	kw_1231[6] = {
		{"environment",0x108,15,1,1,kw_15,0.,0.,0,NIDRProblemDescDB::env_start},
		{"interface",8,12,5,5,kw_40,0.,0.,0,N_ifm3(start,0,stop)},
		{"method",8,105,2,2,kw_1063,0.,0.,0,N_mdm3(start,0,stop)},
		{"model",8,12,3,3,kw_1158,0.,0.,0,N_mom3(start,0,stop)},
		{"responses",8,20,6,6,kw_1185,0.,0.,0,N_rem3(start,0,stop)},
		{"variables",8,42,4,4,kw_1230,0.,0.,0,N_vam3(start,0,stop)}
		};

} // namespace Dakota

#ifdef __cplusplus
extern "C" {
#endif
KeyWord Dakota_Keyword_Top = {"KeywordTop",0,6,0,0,Dakota::kw_1231};
#ifdef __cplusplus
}
#endif
