install(
    TARGETS minicc_exe
    RUNTIME COMPONENT minicc_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
