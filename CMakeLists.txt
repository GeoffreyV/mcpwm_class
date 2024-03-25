idf_component_register(SRCS "CDeadTime" "COperator.cpp" "CMcpwm.cpp" "CGenerator.cpp" "CComparator.cpp" "CTimer.cpp" "mcpwm_class.c" "COperatorComplementaryHigh.cpp"
                    INCLUDE_DIRS "include"
                    REQUIRES driver)

target_compile_options(${COMPONENT_LIB} PRIVATE -std=gnu++11)

