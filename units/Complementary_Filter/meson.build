# GENERATED CODE - DO NOT MODIFY BY HAND

units_source += files('Unit/src/Complementary_Filter.c')

unit_test_files = files([
	'UnitTest/src/TestSuites.c',
	'UnitTest/src/userstub.c',
	'UnitTest/src/Run_Test.c',
	'UnitTest/src/InitTest.c'
])

cc = meson.get_compiler('c', native: true)

preprocessed_file = cc.preprocess(
        'Unit/src/Complementary_Filter.c',
        include_directories: [
                stub_include,
                units_include,
                platform_include,
                integration_include,
                unittest_include,
        ],
        compile_args: [
                stub_args,
                '-DPLATFORM=0',
                '-DUNIT_TEST=1',
                '-nostdinc'
        ]
)

mock_generator = generator(
        python,
        output: [ '@BASENAME@_mock.c', '@BASENAME@_mock.h', '@BASENAME@_mock_internal.h'],
        arguments: [
                meson.global_source_root() + '/scripts/UnitTestSupport.py',
                '@BUILD_DIR@',
                '@INPUT@',
                '@OUTPUT0@',
                '@OUTPUT1@',
                '@OUTPUT2@',
                '@0@/@1@'.format(meson.current_source_dir(),'Unit/src/Complementary_Filter.c'),

        ]
)

mocks = mock_generator.process(
        preprocessed_file
)

test(
        'Complementary_Filter_test', 
        executable(
                'Complementary_Filter_test', 
                'Unit/src/Complementary_Filter.c',
                unittest_source,
                unit_test_files,
                mocks,
                include_directories: [
                        units_include,
                        platform_include,
                        integration_include,
                        unittest_include,
                        include_directories('UnitTest/include')
                ],
                c_args: ['-DPLATFORM=0', '-DUNIT_TEST=1', '-g'],
                native: true
        ),
        protocol: 'tap',
)

if get_option('target_tests') == true

test(
        'Complementary_Filter_target_test',
        python, 
        args: 
                [
                        test_runner,
                        executable(
                                'Complementary_Filter_target_test',
                                'Unit/src/Complementary_Filter.c',
                                unit_test_files,
                                mocks,
                                unittest_source,
                                unittest_platform_source,
                                platform_source_bareMinimum,
                                name_suffix: 'elf',
                                include_directories: [
                                        units_include,
                                        platform_include,
                                        integration_include,
                                        unittest_include,
                                        unittest_platform_include,
                                        include_directories('UnitTest/include')
                                ],
                                c_args: [ platform_cflags, '-DPLATFORM=1', '-DUNIT_TEST=1'],
                                link_args: [ link_args ],
                                override_options: [
                                        'b_coverage=false'
                                ]
                        ).full_path()
                ], 
        protocol: 'tap',
        is_parallel : false
)

endif

# END GENERATED CODE