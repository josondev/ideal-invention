#before running this,run the following commands in a terminal or in a separate codecell

'''pip install lyzr,pip install aenum,pip install playwright(Playwright is a Python library to automate Chromium, Firefox and WebKit browsers with a single API.)
pip install youtube_transcripts_api,pip install nest_asyncio(to prevent running of two loops incase of website,webpage and youtube videos)
!sudo apt-get install libwoff2dec-bin libgstreamer1.0-0 libgstreamer-plugins-base1.0-0 libharfbuzz-icu0(missing libraries in playwright)'''

#main function:

def main(key):
  ans=input('voice or search or chat or generator or summariser:')
  if(ans=='voice'):
    ans=input('Text-to-speech or Transcribe or Text-to-notes:')
    Voice(ans,key)
  elif(ans=='summariser'):
    Summariser(key)
  elif(ans=='generator'):
    Generator(key)
  else:
    from google.colab import files
    import os
    import nest_asyncio  #The error message "RuntimeError: This event loop is already running" usually arises in asynchronous programming when you try to start a new event loop while another is already active'''
    from lyzr import ChatBot
    from lyzr import SearchAgent #Chatbot from lyzr      
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

#sub function definitions start here:

def Voice(ans,key):
  from lyzr import VoiceBot
  vb=VoiceBot(api_key=key)
  if(ans=='Text-to-speech'):   
    vb.text_to_speech(input('enter the text to be converted to speech:'))
    print('Successful execution.Please check the files.')
  elif(ans=='Text-to-notes'):
    print(vb.text_to_notes(input('enter the text to be converted to notes:')))
  elif(ans=="Transcribe"):
    print(vb.transcribe(input('enter the audio file to be converted to text:')))
  else:
    print("enter a valid operation.")

def Summariser(key):
  from lyzr import Summarizer
  summarizer = Summarizer(api_key=key)
  ans=input('enter the text to be converted to a summary:')
  print(summarizer.summarize(ans))

def Generator(key):
  from lyzr import Generator
  generator=Generator(api_key=key)
  ans=input('enter the topic to be expanded:')
  print(generator.generate(ans))

def Chat(ans):
  if(ans=='pdf'):
    Chat_pdf()
  elif(ans=="word document"):
    Chat_word()
  elif(ans=="text file"):
    Chat_text()
  else:
    if(ans=='youtube video'):
      Chat_youtube(input("enter the youtube video link:"))
    elif(ans=='website'):
      Chat_website(input('enter the website link:'))
    elif(ans=='webpage'):
      Chat_webpage(input('enter the webpage link:'))

def Search(ans):
  if(ans=='pdf'):
    Search_pdf()
  elif(ans=='word document'):
    Search_word()
  elif(ans=='text file'):
    Search_text()
  else:
      if(ans=='youtube video'):
        Search_youtube(input("enter  the youtube video link:"))
      elif(ans=='website'):
        Search_website(input('enter the website link:'))
      elif(ans=="webpage"):
        Search_webpage(input('enter the webpage link:'))  

def Chat_pdf():
  from google.colab import files
  from lyzr import ChatBot
  while(1):
      try:
          uploaded = files.upload()  # Returns a dictionary
          filename = next(iter(uploaded))
          search_agent = ChatBot.pdf_chat(input_files=[filename])  # Create SearchAgent from PDF
          ans = input("Your question here:")
          response = search_agent.query(ans)  # Use search method
          print(response)
          break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Chat_text():
  from google.colab import files
  from lyzr import ChatBot
  while(1):
      try:
          uploaded = files.upload()  # Returns a dictionary
          filename = next(iter(uploaded))
          search_agent = ChatBot.txt_chat(input_files=[filename])  # Create SearchAgent from text files
          ans = input("Your question here:")
          response = search_agent.query(ans)  # Use search method
          print(response)
          break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Chat_word():
  from google.colab import files
  from lyzr import ChatBot
  while(1):
      try:
          uploaded = files.upload()  # Returns a dictionary
          filename = next(iter(uploaded))
          search_agent = ChatBot.docx_chat(input_files=[filename])  # Create SearchAgent from word document
          ans = input("Your question here:")
          response = search_agent.query(ans)  # Use search method
          print(response)
          break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Chat_youtube(ans):
  while 1:
    try: 
      chatbot = ChatBot.youtube_chat(urls=[ans])  
      ans = input("Your question here:")
      response = chatbot.chat(ans)
      print(response.response)
      break
    except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Chat_website(ans):
    while 1:
      try:
        chatbot = ChatBot.website_chat(urls=[ans])  
        ans = input("Your question here:")
        response = chatbot.chat(ans)
        print(response.response)
        break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Chat_webpage(ans):
  from lyzr import ChatBot
  while(1):
    try:
      chatbot=ChatBot.webpage_chat(urls=[ans])
      ans=input('your question here:')
      result=chatbot.query(ans)
      print(result)
      break
    except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Search_pdf():
  from google.colab import files
  from lyzr import SearchAgent
  while(1):
    try:
      uploaded = files.upload()  # Returns a dictionary
      filename = next(iter(uploaded))
      search_agent = SearchAgent.add_pdf(input_files=[filename])  # Create Search
      ans = input("Your question here:")
      response = search_agent.query(ans)
      print(response.response)
      break
    except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Search_text():
  from google.colab import files
  from lyzr import SearchAgent
  while(1):
    try:
      uploaded = files.upload()  # Returns a dictionary
      filename = next(iter(uploaded))
      search_agent = SearchAgent.add_text(input_files=[filename])  # Create Search
      ans = input("Your question here:")
      response = search_agent.query(ans)
      print(response.response)
      break
    except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Search_word():
  from google.colab import files
  from lyzr import SearchAgent
  while(1):
    try:
      uploaded = files.upload()  # Returns a dictionary
      filename = next(iter(uploaded))
      search_agent = SearchAgent.add_docx(input_files=[filename])  # Create Search
      ans = input("Your question here:")
      response = search_agent.query(ans)
      print(response.response)
      break
    except Exception as e:  # Catch any exception and assign it to 'e'
      print(f'An error occurred: {e}')    

def Search_youtube(ans):
    from lyzr import SearchAgent
    while 1:
      try:
        search_agent = SearchAgent.add_youtube(ans)  
        ans = input("Your question here:")
        response = search_agent.query(ans)
        print(response.response)
        break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')   

def Search_website(ans):
    from lyzr import SearchAgent
    while(1):
      try:
        search_agent=SearchAgent.add_website(ans)
        ans=input('your question here:')
        result=search_agent.query(ans)
        print(result)
        break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

def Search_webpage(ans):
    from lyzr import SearchAgent
    while(1):
      try:
        search_agent=SearchAgent.add_webpage(ans)
        ans=input('your question here:')
        result=search_agent.query(ans)
        print(result)
        break
      except Exception as e:  # Catch any exception and assign it to 'e'
        print(f'An error occurred: {e}')

if(__name__=='__main__'):
  key=input('enter your api key:')
  main(key)  #main function call
