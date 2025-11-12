#various operations on Sets


A={1,2,3,4}
B={2,3,4,5,6,7,8}

print("ASet=",A)
print("B Set=",B)
print("lengthlofA=",len(A))
print("maximum of B:",max(B))
print("minimum of A:",min(A))
print("Aunion B =",A.union(B))
print("A intersection B=",A.intersection(B))
print("A difference B=",A.difference(B))
print("Asymmetric difference B=",A.symmetric_difference(B))
print("A is subset of B:",A.issubset(B))
print("A is superset of B:",A.issuperset(B)) 
A.add(9)
print("After Adding new element 9 toset A:",A) 
B.remove(4)
print("After Deleting 4 from setB",B)
print("sorted value from the union of A and B: ", sorted(A.union(B)))