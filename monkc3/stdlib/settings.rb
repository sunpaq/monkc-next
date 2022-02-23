#!/usr/bin/ruby
require 'mcbuild'

$stdlib = MCBuild.new(__dir__)
	.set_name("stdlib")
	.set_dependency([
		$runtime,
	])
