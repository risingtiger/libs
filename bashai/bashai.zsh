
ba() {
	if [[ $# -eq 0 ]]; then
		echo 'usage: bashai-prompt "describe command"' >&2
		return 1
	fi

	local command
	command="$(bashai "$@")" || return $?
	print -z -- "$command"
}
