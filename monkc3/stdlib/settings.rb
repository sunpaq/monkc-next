#!/usr/bin/ruby
require 'mcbuild'

$stdlib = MCBuild.new(__dir__)
	.set_name("monkc-stdlib")
	.set_dependency([
		$runtime,
	])
