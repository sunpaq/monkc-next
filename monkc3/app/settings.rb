#!/usr/bin/ruby
require 'mcbuild'

$app = MCBuild.new(__dir__)
	.set_name("app")
	.set_dependency([
		$runtime, 
		$stdlib,
		$platform,
	])
