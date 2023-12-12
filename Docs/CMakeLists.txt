set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

doxygen_add_docs(docs "${PROJECT_SOURCE_DIR}/Include"  
                      "${PROJECT_SOURCE_DIR}/Src" 
                      "${PROJECT_SOURCE_DIR}/Docs"
		      "${PROJECT_SOURCE_DIR}/Src_autogen"
                 WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/Include")