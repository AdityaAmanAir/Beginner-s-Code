
#for j in B:

# B_inv=[[1,1,1],
#    [4,5,6],
#    [7,7,9]]
def martixMult(A,B):
    lenAR=len(A)
    lenAC=len(A[0])
    lenBR=len(B)
    lenBC=len(B[0])

    resultMatrix=[]

    # B_inv=[]
    # for y in range(len(B[0])):
    #     for x in range(len(B)):
    #         e= B[x][y]
    #         B_inv[y].append(e)
    # print(B_inv)        


    if(lenAC!=lenBR):
        print("Multiplicationn not Possible")
        return -1
    else:
        for i in range(lenAR):
            for j in range(lenBC):
                ans=A[i][j]*B[i][j]
                resultMatrix.append(ans)
                
        print(resultMatrix)


# print(lenAC,lenAR,lenBC,lenBR)
# for i in range(len(A)):
#     for j in A[i]:
#         e=j*








A=[[1,2,3],
   [4,5,6],
   [7,8,9]]
B=[[1,1,1],
   [4,5,6],
   [7,7,9]]

martixMult(A,B)