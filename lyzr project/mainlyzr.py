'''from google.colab import files
import os
import nest_asyncio  #The error message "RuntimeError: This event loop is already running" usually arises in asynchronous programming when you try to start a new event loop while another is already active that is one instruction must not run when execution of another is happening'''
from lyzr import ChatBot
from lyzr import SearchAgent #Chatbot from lyzr

class MAIN:
  
  def __init__(self,ans,key):
    self.ans=ans
    self.__key=key

  def getKey(self):
    return(self.__key)

  def SetKey(self,key):
    self.__key=key

  def main(self,ans,key):
    if(ans=='voice'):
      ans=input('Text-to-speech or Transcribe or Text-to-notes:')
      Voice(ans,key)
    elif(ans=='summariser'):
      Summariser(key)
    elif(ans=='generator'):
      Generator(key)
    else:
      nest_asyncio.apply()
      os.environ['OPENAI_API_KEY'] = key
      if(ans=='chat'):
        ans=input('word document or pdf or youtube video or website or webpage or text file:')
        Chat(ans)
      elif(ans=='search'):
        ans=input('word document or pdf or youtube video or website or webpage or text file:')
        Search(ans)
      else:
          print("enter a valid operation:")
        
if(__name__=='__main__'):
  while(1):
    try:
      ans=input('voice or search or chat or generator or summariser:')
      key=input('enter your api key:')
      obj=MAIN(ans,key)
      obj.SetKey(key)
      obj.main(ans,key)       
    except Exception as e:
      print("the following exception has occured:",e)
    finally:
      print("do you want to continue?:")
      ans=input("enter yes or no:")
      if(ans=="no"):
        print("exiting program.")
        break'''

import os
import nest_asyncio  # Ensure this is applied before asynchronous operations
from lyzr import ChatBot, SearchAgent  # Assuming these are correct imports

# Apply nest_asyncio once at the start
nest_asyncio.apply()

class MAIN:
    def __init__(self, ans, key):
        self.ans = ans
        self.__key = key

    def getKey(self):
        return self.__key

    def setKey(self, key):
        self.__key = key

    def main(self):
        if self.ans == 'voice':
            ans = input('Text-to-speech or Transcribe or Text-to-notes: ')
            Voice(ans, self.__key)
        elif self.ans == 'summariser':
            Summariser(self.__key)
        elif self.ans == 'generator':
            Generator(self.__key)
        else:
            os.environ['OPENAI_API_KEY'] = self.__key
            if self.ans == 'chat':
                ans = input('word document or pdf or youtube video or website or webpage or text file: ')
                Chat(ans)
            elif self.ans == 'search':
                ans = input('word document or pdf or youtube video or website or webpage or text file: ')
                Search(ans)
            else:
                print("Enter a valid operation:")

if __name__ == '__main__':
    while True:
        try:
            ans = input('voice or search or chat or generator or summariser: ')
            key = input('Enter your API key: ')
            obj = MAIN(ans, key)
            obj.setKey(key)
            obj.main()
        except Exception as e:
            print("The following exception has occurred:", e)
        finally:
            continue_program = input("Do you want to continue? (yes or no): ")
            if continue_program.lower() == "no":
                print("Exiting program.")
                break

    
      
