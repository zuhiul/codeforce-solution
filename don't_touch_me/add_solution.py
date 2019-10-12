import sys
if __name__ == "__main__":
	if len(sys.argv) != 3:
		print("please give me problem ID")
		exit(0)
	contest_id = str(sys.argv[1])
	problem_id = str(sys.argv[2])
	with open('../README.md', 'a+') as f:
		contest_name = '[' + contest_id + problem_id + ']'
		contest_link = '(https://codeforces.com/problemset/problem/' + contest_id + '/' + problem_id + ')'
		github_name = '[solution]'
		github_link = '(https://github.com/zuhiul/codeforce-solution/blob/master/' + contest_id + '/' + problem_id + '.cpp)'
		f.write(contest_name + contest_link + ' : ' + github_name + github_link + '\n')
