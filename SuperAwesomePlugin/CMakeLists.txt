project(SuperAwesomePlugin)

add_library( ${PROJECT_NAME}
        SHARED
        source/SuperAwesomePlugin.cpp
        )

install(
        TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib/plugins/dobby
        NAMELINK_SKIP
        )

target_link_libraries(${PROJECT_NAME}
        DobbyRdkPluginCommonLib
)

set_target_properties( ${PROJECT_NAME} PROPERTIES SOVERSION 1 )
