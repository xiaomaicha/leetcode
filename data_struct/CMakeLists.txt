file(GLOB CPP_FILES *.cpp)

foreach (SAMPLE_SOURCE ${CPP_FILES})
  #  message(SATTUS "SOURCE: " ${SAMPLE_SOURCE})
  string(REGEX REPLACE ".+/(.+)\\..*" "\\1" SAMPLE_NAME ${SAMPLE_SOURCE})
  add_executable(${SAMPLE_NAME} ${SAMPLE_SOURCE})
  target_link_libraries(${SAMPLE_NAME})
endforeach (SAMPLE_SOURCE ${CPP_FILES})
