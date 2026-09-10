class Solution(object):

    def isValid(self, s):

        stack=[]

        for x in s:

            if x=='(' or x=='[' or x=='{':

                stack.append(x)

            else:

                if len(stack)==0:
                    return False

                elif x==')':

                    if stack[-1]!='(':
                        return False

                elif x=='}':

                    if stack[-1]!='{':
                        return False

                elif x==']':

                    if stack[-1]!='[':
                        return False

                stack.pop()

        return len(stack)==0