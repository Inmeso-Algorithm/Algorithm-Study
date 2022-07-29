object_list = []
score_list = [0.0]
grade_list = [0.0]
result_list = [0.0]

dic = {'A+': 4.5, 'A0': 4.0, 'B+': 3.5, 'B0': 3.0, 'C+': 2.5, 'C0': 2.0, 'D+': 1.5, 'D0': 1.0, 'F': 0.0, 'P': 0.0}


def result(y):
    if y == "P":
        return False
    return True


def converter(n):
    return dic[n]


for i in range(20):
    object, score, grade = input().split()
    convertGrade = converter(grade)
    if result(grade):
        object_list.append(object)
        score_list.append(round(float(score), 7))
        grade_list.append(round(convertGrade, 7))

for i in range(len(score_list)):
    result_list += [float(score_list[i] * grade_list[i])]

print("0.000000" if sum(score_list) == 0 else round(float(sum(result_list) / sum(score_list)), 6))
