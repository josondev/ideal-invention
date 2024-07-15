key='your OPENAI key'

ans=input('voice or search or chat or generator or summariser:')

if(ans=='voice'):
  from lyzr import VoiceBot
  vb=VoiceBot(api_key=key)
  ans=input('Text-to-speech or Transcribe or Text-to-notes:')
  if(ans=='Text-to-speech'):
    vb.text_to_speech(input('enter the text to be converted to speech:'))
    print('Successful execution.Please check the files.')
  elif(ans=='Text-to-notes'):
    print(vb.text_to_notes(input('enter the text to be converted to notes:')))
  else:
    print(vb.transcribe(input('enter the audio file to be converted to text:')))

elif(ans=='summariser'):
  from lyzr import Summarizer
  summarizer = Summarizer(api_key=key)
  ans=input('enter the text to be converted to a summary:')
  instructions=input('suummary,notes or tweet:')
  print(summarizer.summarize(ans))

elif(ans=='generator'):
  from lyzr import Generator
  generator=Generator(api_key=key)
  ans=input('enter the topic to be expanded:')
  persona=input('target audience:')
  print(generator.generate(ans))

else:
  # Prompt user to upload a folder
  if(ans=='chat'):
    from google.colab import files
    import os
    from lyzr import ChatBot
    os.environ['OPENAI_API_KEY'] = key
    ans=input('word document or pdf or youtube video or website or webpage or text file:')
    if(ans=='pdf'):
      while(1):
        try:
          uploaded = files.upload()  # Returns a dictionary
          filename = next(iter(uploaded))
          '''with open(filename, 'wb') as f:  # Save the uploaded file
            f.write(uploaded[filename])'''  # Get the filename
          chatbot = ChatBot.pdf_chat(input_files=[filename])  # Pass the filename to pdf_chat
          ans = input("Your question here:")
          response = chatbot.chat(ans)
          print(response.response)
          break
        except:
          print('please enter the correct pdf file.')

    elif(ans=='word document'):
      while(1):
        try:
          uploaded = files.upload()  # Returns a dictionary
          filename = next(iter(uploaded))  # Get the filename
          chatbot = ChatBot.docx_chat(input_files=[filename])  # Pass the filename to docx_chat
          ans = input("Your question here:")
          response = chatbot.chat(ans)
          print(response.response)
          break
        except:
          print('please enter the correct word document.')

    elif(ans=='text file'):
      while(1):
        try:
          uploaded = files.upload()  # Returns a dictionary
          filename = next(iter(uploaded))  # Get the filename
          chatbot = ChatBot.txt_chat(input_files=[filename])  # Pass the filename to text_chat
          ans = input("Your question here:")
          response = chatbot.chat(ans)
          print(response.response)
          break
        except:
          print('please enter the correct text file.')
    else:
      if(ans=='youtube video'):
        while(1):
          try:
            ans=input('enter youtube video link:')  # Returns a dictionary
            chatbot = ChatBot.youtube_chat(urls=[ans])  # Pass the filename to pdf_chat
            ans = input("Your question here:")
            response = chatbot.chat(ans)
            print(response.response)
            break
          except:
            print('enter the proper youtube video link:')

      elif(ans=='website'):
        import nest_asyncio       #The error message "RuntimeError: This event loop is already running" usually arises in asynchronous programming when you try to start a new event loop while another is already active'''
        nest_asyncio.apply()      #prevents conflicting loops
        ans=input('enter website link:') # Returns a dictionary
        while(1):
          try:
            chatbot = ChatBot.website_chat(ans)  # Pass the link
            ans = input("Your question here:")
            response = chatbot.chat(ans)        #fails for chromium based applications idk y  :(
            print(response.response)
            break
          except:
            print("enter the proper website link:")

      elif(ans=='webpage'):
        import nest_asyncio       #The error message "RuntimeError: This event loop is already running" usually arises in asynchronous programming when you try to start a new event loop while another is already active'''
        nest_asyncio.apply()      #prevents conflicting loops
        ans=input('enter webpage link:') # Returns a dictionary
        while(1):
          try:
            chatbot = ChatBot.webpage_chat(ans)  # Pass the link
            ans = input("Your question here:")
            response = chatbot.chat(ans)        #fails for chromium based applications idk y  :(
            print(response.response)
            break
          except:
            print("enter the proper webpage link:")
  else:
    #else:
    from google.colab import files
    import os
    from lyzr import SearchAgent  # Import SearchAgent from lyzr
    os.environ['OPENAI_API_KEY'] = key
    ans=input('word document or pdf or youtube video or website or webpage or text file:')
    if(ans=='pdf'):
      #while(1):
        #try:
      uploaded = files.upload()  # Returns a dictionary
      filename = next(iter(uploaded))
      search_agent = SearchAgent.add_pdf(input_files=[filename])  # Create SearchAgent from PDF
      ans = input("Your question here:")
      response = search_agent.query(ans)  # Use search method
      print(response)
          #break
        #except:
          #print('please enter the correct pdf file.')

    elif(ans=='word document'):
      #while(1):
        #try:
      uploaded = files.upload()  # Returns a dictionary
      filename = next(iter(uploaded))
      search_agent = SearchAgent.add_docx(input_files=[filename])  # Create SearchAgent from PDF
      ans = input("Your question here:")
      response = search_agent.query(ans)  # Use search method
      print(response)
          #break
        #except:
          #print('please enter the correct word document.')

    elif(ans=='text file'):
      while(1):
        try:
          uploaded=files.upload()
          filename=next(iter(uploaded))
          search_agent=SearchAgent.add_text(input_files=[filename])
          ans=input('your question here:')
          response=search_agent.query(ans)
          print(response)
          break
        except:
          print('please enter the correct text file')

    #else:
    elif(ans=='youtube video'):
      while(1):
        try:
          ans=input('enter youtube video link:')  # Returns a dictionary
          search_agent = SearchAgent.add_youtube(ans)  # Pass the filename to pdf_chat
          ans = input("Your question here:")
          response = search_agent.query(ans)
          print(response.response)
          break
        except:
          print('enter the proper youtube video link:')


    elif(ans=='website'):
      import nest_asyncio
      nest_asyncio.apply()
      while(1):
        try:
          search_agent=SearchAgent.add_website(input('enter website link:'))
          ans=input('your question here:')
          result=search_agent.query(ans)
          print(result)
          break
        except:
          print('please enter the proper website link:')

    elif(ans=='webpage'):
      import nest_asyncio
      nest_asyncio.apply()
      while(1):
        try:
          search_agent=SearchAgent.add_webpage(input('enter webpage link:'))
          ans=input('your question here:')
          result=search_agent.query(ans)
          print(result)
          break
        except:
          print('please enter the proper webpage link:')
