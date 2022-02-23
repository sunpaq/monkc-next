#!/usr/bin/ruby
require 'mcbuild'

$platform = MCBuild.new(__dir__)
	.set_name("monkc-platform")
	.set_dependency([
		$runtime, 
		$stdlib,
	])
