{
	'targets': [
		{
			'target_name': 'main_dst',
			'type': 'none',
			'dependencies': [
				'main',
			],
			'copies': [
				{
					'destination': '.',
					'files': [
						'out/Default/main',
					],
				},
			],
		},
		{
			'target_name': 'main',
			'type': 'executable',
			'sources': [
				'main.cpp',
				'basic_config.h',
				'logging.h',
				'main_application.cpp',
				'main_application.h',
				'quad_test.h',
				'quad_test.cpp',
				'cube.cpp',
				'cube.h',
				'wc_rect.cpp',
				'wc_rect.h',
				'wc_eclipse.cpp',
				'wc_eclipse.h',
				'wc_bitmap.cpp',
				'wc_bitmap.h',
				'wc_list.h',
				'wc_list.cpp',
				'wc_line.h',
				'wc_line.cpp',
				'wc_fill.cpp',
				'wc_fill.h',
			],
			'libraries': [
				'-lGL',
				'-lGLU',
				'-lglut',
			],
		},
	],	
}
