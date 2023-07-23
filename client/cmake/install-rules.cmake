install(
    TARGETS rrr_exe
    RUNTIME COMPONENT rrr_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
