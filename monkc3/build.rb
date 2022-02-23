#!/usr/bin/ruby
require 'mcbuild'

build = MCBuild.new(__dir__).include ['runtime', 'stdlib', 'platform', 'app']

libs = [
	$runtime, 
	$stdlib,
	$platform
]

build.command 'clean' do
	libs.each { |lib|
		lib.clean
	}
	$app.clean
end

build.command 'all' do
	libs.each { |lib|
		lib.set_std("c11")
		lib.info.compile.archive_lib
	}
	$app.set_std("c11")
	$app.info.compile.archive_exe.done
end

build.command 'run' do
	$app.run
end

build.print ["clean", "all", "run"]
