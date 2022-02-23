#!/usr/bin/ruby
require 'mcbuild'

$platform = MCBuild.new(__dir__)
	.set_name("platform")
	.set_dependency([
		$runtime, 
		$stdlib,
	])
