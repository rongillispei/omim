project(search_quality_tool)

include_directories(${OMIM_ROOT}/3party/gflags/src)
include_directories(${OMIM_ROOT}/3party/jansson/src)

set(SRC search_quality_tool.cpp)

omim_add_executable(${PROJECT_NAME} ${SRC})

omim_link_libraries(
  ${PROJECT_NAME}
  search_tests_support
  search
  search_quality
  storage
  editor
  indexer
  platform
  mwm_diff
  bsdiff
  geometry
  coding
  base
  oauthcpp
  gflags
  jansson
  protobuf
  stats_client
  minizip
  succinct
  opening_hours
  pugixml
  icu
  ${Qt5Core_LIBRARIES}
  ${Qt5Network_LIBRARIES}
  ${LIBZ}
)
