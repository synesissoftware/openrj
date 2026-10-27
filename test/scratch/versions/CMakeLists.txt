define_example_program(test.scratch.versions main.c)

target_link_libraries(test.scratch.versions
	PRIVATE
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
)

if(shwild_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			shwild::core
	)
endif()

if(TARGET xTests::core)

	target_link_libraries(test.scratch.versions
		PRIVATE
			xTests::core
	)
endif()
