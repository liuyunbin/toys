
add_executable(tinylog_time_stamp_unit_test tinylog_time_stamp_unit_test.cc)
target_link_libraries(tinylog_time_stamp_unit_test tinylog_static gtest_main)

add_executable(tinylog_log_buffer_unit_test tinylog_log_buffer_unit_test.cc)
target_link_libraries(tinylog_log_buffer_unit_test tinylog_static gtest_main)

add_executable(tinylog_log_stream_unit_test tinylog_log_stream_unit_test.cc)
target_link_libraries(tinylog_log_stream_unit_test tinylog_static gtest_main)

add_executable(tinylog_log_format_unit_test tinylog_log_format_unit_test.cc)
target_link_libraries(tinylog_log_format_unit_test tinylog_static gtest_main)

add_executable(tinylog_logging_bench_test tinylog_logging_bench_test.cc)
target_link_libraries(tinylog_logging_bench_test tinylog_static gtest_main)

add_executable(tinylog_logging_async_test tinylog_logging_async_test.cc)
target_link_libraries(tinylog_logging_async_test tinylog_static gtest_main)

