{
	'targets': [
		{
			'target_name': 'main',
			'type': 'executable',
			'sources': [
				'main.cpp',
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
