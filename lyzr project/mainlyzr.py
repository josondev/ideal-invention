from google.colab import files
import os
import nest_asyncio  #The error message "RuntimeError: This event loop is already running" usually arises in asynchronous programming when you try to start a new event loop while another is already active that is one instruction must not run when execution of another is happening'''
from lyzr import ChatBot
from lyzr import SearchAgent #Chatbot from lyzr

class MAIN:
  
  def __init__(self,ans,key):
    self.ans=ans
    self.key=key
    
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
      MAIN(ans,key).main(ans,key)       
    except Exception as e:
      print("the following exception has occured:",e)
    finally:
      print("do you want to continue?:")
      ans=input("enter yes or no:")
      if(ans=="no"):
        print("exiting program.")
        break
    
    
      
