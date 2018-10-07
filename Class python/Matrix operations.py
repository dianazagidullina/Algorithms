from sys import stdin
import copy


class MatrixError(BaseException):
    def __init__(self, Matrix, other):
        self.matrix1 = Matrix
        self.matrix2 = other


class Matrix:
    def __init__(self, a):
        self.a = copy.deepcopy(a)

    def __str__(self):
        s = ''
        for i in range(len(self.a)):
            for j in range(len(self.a[i])):
                s += str(self.a[i][j])
                if j != len(self.a[i]) - 1:
                    s += '\t'
            if i != len(self.a) - 1:
                s += '\n'
        return s

    def size(self):
        return (len(self.a), len(self.a[0]))

    def __add__(self, other):
        if self.size() == other.size():
            ans = copy.deepcopy(self.a)
            for i in range(len(self.a)):
                for j in range(len(self.a[i])):
                    ans[i][j] += other.a[i][j]
            ans = Matrix(ans)
            return ans
        else:
            raise MatrixError(self, other)

    def __mul__(self, other):
        if not isinstance(other, Matrix):
            ans = copy.deepcopy(self.a)
            for i in range(len(self.a)):
                for j in range(len(self.a[i])):
                    ans[i][j] *= other
        else:
            szSelf = self.size()
            szOther = other.size()
            if szSelf[1] == szOther[0]:
                ans = list()
                for i in range(szSelf[0]):
                    ans.append([0] * szOther[1])
                for i in range(szSelf[0]):
                    for j in range(szOther[1]):
                        for k in range(szSelf[1]):
                            ans[i][j] += self.a[i][k] * other.a[k][j]
            else:
                raise MatrixError(self, other)
        ans = Matrix(ans)
        return ans
    __rmul__ = __mul__

    def transpose(self):
        sz = self.size()
        ans = list()
        for i in range(sz[1]):
            ans.append([self.a[0][i], ])
            for j in range(1, sz[0]):
                ans[i].append(self.a[j][i])
        self.a = ans
        return self

    @staticmethod
    def transposed(self):
        sz = self.size()
        ans = list()
        for i in range(sz[1]):
            ans.append([self.a[0][i], ])
            for j in range(1, sz[0]):
                ans[i].append(self.a[j][i])
        return Matrix(ans)


class SquareMatrix(Matrix):
    def __pow__(self, alpha):
        if alpha == 0 or alpha == 1:
            return self
        elif alpha % 2 == 0:
            ans = self ** (alpha // 2)
            ans = ans * ans
        else:
            ans = self * (self ** (alpha - 1))
        return ans

exec(stdin.read())