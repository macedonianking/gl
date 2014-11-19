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
			],
			'libraries': [
				'-lGL',
				'-lGLU',
				'-lglut',
			],
		},
	],	
}
