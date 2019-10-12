import sys
import os
def transfer(problem) :
	for ind in range(len(problem)):
		if problem[ind] not in '0123456789':
			return problem[:ind], problem[ind:]
	exit(0)

def add(contest_id, problem_id):
	with open('../README.md', 'a+') as f:
		contest_name = '[' + contest_id + problem_id + ']'
		contest_link = '(https://codeforces.com/problemset/problem/' + contest_id + '/' + problem_id + ')'
		github_name = '[solution]'
		github_link = '(https://github.com/zuhiul/codeforce-solution/blob/master/' + contest_id + '/' + problem_id + '.cpp)'
		f.write(contest_name + contest_link + ' : ' + github_name + github_link + '\n\n')

if __name__ == '__main__':
	if len(sys.argv) != 2:
		print("please give me the path")
		exit(0)
	filePath = str(sys.argv[1])
	problem_list = []
	for i,j,k in os.walk(filePath):
		if 'cpp' not in ''.join(k):
			continue
		last_ind = i.rfind('/')
		for name in k:
			ind = name.rfind('.')
			problem_list.append(i[last_ind+1:] + name[:ind])
	problem_list.sort()
	for problem in problem_list:
		contest_id, problem_id = transfer(problem)
		add(contest_id, problem_id)
