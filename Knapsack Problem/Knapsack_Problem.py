
def DynamicKnapsack(A_matrix, items, C):
    # A_matrix[c][i]
    optimal_vol=0
    for c in range(0, C+1):
        A_matrix[c].append(0)
    for i in range(1, len(items['si'])):
        for c in range(0, C+1):
                if(items['si'][i]>(c)):
                    A_matrix[c].append(A_matrix[c][i-1])
                else:   #tests if the left most item is > the function
                    if(A_matrix[c][i-1] > (A_matrix[c-items['si'][i]][i-1]
                            +(items['vi'][i]))):
                        A_matrix[c].append(A_matrix[c][i-1])
                        optimal_vol = A_matrix[c][i - 1]
                    else: #all other cases of equal or greater than the left item
                        A_matrix[c].append((A_matrix[c-items['si'][i]][i-1]
                            +items['vi'][i]))
                        #saves each change until optimal volume is reached
                        optimal_vol=(A_matrix[c-items['si'][i]][i-1]
                            +items['vi'][i])

    return A_matrix, optimal_vol
def KnapsackReconstruction(matrix_A, item, C):
    c=C
    S=[]
    #Itterates for each length i
    #if c and i>0 adds a value to the list if it's
    for i in reversed(range(1, len(item['num']))):
        #tests if items are in the list range
       if((c>=item['si'][i])&((matrix_A[c-item['si'][i]][i-1]+item['vi'][i])>=matrix_A[c][i-1])):
            S.append(i)
            c=c-item['si'][i]
    return S

C=5
items={}
items['num']=[0, 1, 2, 3, 4]
items['vi']=[0, 15, 10, 20, 12]
items['si']=[0, 2, 1, 3, 2]
print('Items')
print('item | vi | si')
for i in range(0, len(items['vi'])):
    print("   {a} | {b} | {c} ".format( a=items['num'][i],
                                       b=items['vi'][i], c=items['si'][i]))
A = [[], [], [], [], [], [], [], [], [], []]
#returns matrix A and optimal volume
A, optimal_volume = DynamicKnapsack(A, items, C)
S =KnapsackReconstruction(A, items, C)
size=len(A)
print('')
#Prints matrix and saves optimal volume
for i in reversed(range(0, size)):
    print(A[i])

print('\noptimal volume is')
print(optimal_volume)
print('\n the optimal solution is:')
print(S)