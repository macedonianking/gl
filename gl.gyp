{
	'targets': [
		{
			'target_name': 'main',
			'type': 'executable',
			'sources': [
				'main.cpp',
				'main_application.cpp',
				'main_application.h',
			],
			'libraries': [
				'-lpthread',
				'-lglut',
				'-lGL',
				'-lGLU',
			],
		},
	],	
}
