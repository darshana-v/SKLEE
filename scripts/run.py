import os
import subprocess
import sys

def convertTestCase(directory):
	for filename in os.listdir(directory):
		homeDir = "./"
		toolPath = directory
		if filename.endswith(".ktest") and filename.startswith("error"):
# print(os.path.join(directory, filename))
			# a = subprocess.check_output([homeDir, 'build/bin/ktest-tool ', toolPath, '/klee-last/', filename, '&>', filename, '.txt'])
			if not filename.startswith("error-early"):
				cmd = homeDir + 'build/bin/ktest-tool ' + toolPath + filename + ' >' + filename + '.txt'
				os.system(cmd)
				# print(a)
				# print("found")
				continue

def result():
	file_read = open("result.txt", "r")
	file_read2 = open("properties.txt", "r")
	file_write = open("result_new.txt", "w", encoding="utf-8")
	lines = file_read2.read()
	flag = False

	for property in properties:
		for line in lines.split("\n"):
			if line == property:
				flag = True
		if flag is False:
			file_write.write("\u2705" + " Verified: " + property + "\n")
		flag = False

	file_write.write("\n")

	lines = file_read.read();
	flag = False
	for line in lines.split("\n"):
		if line.startswith("KLEE: Contract")  or line.startswith("KLEE: Error"): # or line.startswith("State"):
			#print(line)
			flag = True
			file_write.write('\u2716' + " " + line + "\n")
		elif line.startswith("State"):
			flag = True
			file_write.write(line + "\n")
		else:
			index = line.find("KLEE: Contract")
			if(index != -1):
				flag = True
				file_write.write(line[index:] + "\n")
			# else:
			# 	index = line.find("KLEE: done:")
			# 	if(index != -1):
			# 		flag = True
			# 		file_write.write(line[index:] + "\n")

	file_read.close()
	if flag is False:
		file_write.write("No results.")
	file_write.close()


def testcases(dirname):
	file_write = open(dirname + "/alltestcases.txt", "w")
	i = 0
	flag = False
	for filename in os.listdir(dirname):
		root, ext = os.path.splitext(filename)
		if root.startswith('test') or root.startswith('error') and ext == '.txt':
			i = i + 1
			flag = True
			file_write.write("TestCase " + str(i) + "\n")
			file_write.write(filename)
			file_write.write("\n")
			file_read = open(filename, "r")
			lines = file_read.read();
			for line in lines.split("\n"):
				if line.find(" int") != -1 or line.find("name") != -1 or line.find("hex") != -1:
					file_write.write(line)
					file_write.write("\n")
			file_read.close()
			file_write.write("\n")
	if flag is False:
		file_write.write("No Erroneous TestCase\n")
	file_write.close()


properties = ["Unchecked send", "Prodigal", "Greedy", "Suicidal", "Re-entrancy", "Overflow", "Address Typecast", "Mapping read", "Transaction Order Dependence", "Transaction State Dependence", "Block State Dependence", "Memory Overlap", "Payable but no fallback"]
if __name__== "__main__":
	if(int(sys.argv[1]) == 1):
		convertTestCase(sys.argv[2] + "/klee-last/")
	else:
		result()
		testcases(sys.argv[2])
