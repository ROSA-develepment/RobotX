cmake_minimum_required(VERSION 3.8)
project(examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(interfaces REQUIRED)
find_package(rosa REQUIRED)

add_executable(number_publisher src/numberpublisher/NumberPublisherNode.cpp)
ament_target_dependencies(number_publisher interfaces rosa)

add_executable(number_subscriber src/numbersubscriber/NumberSubscriberNode.cpp)
ament_target_dependencies(number_subscriber interfaces rosa)

add_executable(add_two_numbers_client src/addtwonumbersclient/AddTwoNumbersClientNode.cpp src/addtwonumbersclient/client/AddTwoNumbersClient.cpp)
ament_target_dependencies(add_two_numbers_client interfaces rosa)

add_executable(add_two_numbers_server src/addtwonumbersserver/AddTwoNumbersServiceNode.cpp src/addtwonumbersserver/service/AddTwoNumbersService.cpp)
ament_target_dependencies(add_two_numbers_server interfaces rosa)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(
        TARGETS number_publisher
                number_subscriber
                add_two_numbers_client
                add_two_numbers_server
        DESTINATION lib/${PROJECT_NAME}/
)

ament_package()
