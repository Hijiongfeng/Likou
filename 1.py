# class A:
#     def __call__(self):
#         print(1)
#     def __iter__(self):
#         print(2)

#     def __getitem__(self,key):
#         print(3)

#     def __contains__(self):
#         print(4)

# a = A()
# a()

from operator import truth


a = (1,[2,3])
try:
    a[1].extend([1,2])
    print('a')
except TypeError:
    print('b')
except SyntaxError:
    print('c')
except:
    print('d')


class Truth:
    pass
x = Truth()
print(bool(x))

print(1)

print(2)

print("第一次尝试github管理代码")

print("第一次在课题组电脑上修改")


