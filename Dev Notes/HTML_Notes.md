```
- html tags tell the browser how the website should look and what to have there
- basic html tag for all documents
   
    <!DOCTYPE html>
    <html>
         <head>
 
         </head>
         <body>
         
         </body>
         </head>
    <html>

- single/empty tags vs container/paired tags in html
   - single- a tag that does not have any content inside it. It is used to define an element that does not require any additional information or formatting ex <!DOCTYPE html>
   - container- a tag that has both an opening tag and a closing tag. It is used to define an element that contains other elements or content. <div> </div>
- Html tags
   - head tag- defines data abt the document (kinda like the settings)
   - body tag- where the content of the webpage goes
   - title tag- used to hold text (title of the website)
   - meta tag- defines information about a tag
   - html attributes/properties- used to provide additional information about HTML elements and typically used to modify the appearance or behavior of an element.
      - ex. "id" gives a unique identifier to an element, "class" groups elements for styling, "href" specifies the link URL, and "alt" provides a text description of an image for accessibility.
   - header tag- defines headings or subheadings within a web page; different levels of header tags, from h1 to h6, with h1 being the biggest display and the text getting smaller the higher you go
        - <h1> </h1>
    - paragraph tag- <p> </p>, block of text or content that forms a self-contained unit within a web page; used to separate sections of text into readable chunks or to indicate the start of a new idea or topic.
    - bold tag <b></b>- makes stuff bold
    - italics <i> </i>- italicizes stuff
    - break <br/>- creates a new line
    - horizontal line <hr/> - represents a horizontal rule or line, displayed as a straight line across the page
    - <big> - makes stuff big
    - <small> - makes stuff small
    - subscript <sub> - subscript
    - supersript <sup> - superscript
- Comments- <!---- ---->
- Styling/style attributes - define the appearance of an HTML element.
    - <p style="color: red;">This text will be red.</p>
    - <p style="color: green; background-color:green;">Thus rext will be green in a green background</p>
   - available css colors to use https://www.w3schools.com/cssref/css_colors.php
- Formatting a page:
   - <header> defines a header section for a webpage or a section of a webpage (can be used for navigation and stuff )
      - <nav> - used to store naviagation elements
   - <main> defines the main content section of a webpage or a section of a webpage
      - <article> - used to define a self-contained article or piece of content on a webpage
         - <section> - used to define a section of a webpage that groups related content together
   - <footer> defines a footer section for a webpage or a section of a webpage
   - <aside> - used to show content that is on the page yet is getting shown but isnt directly related to the core content of a website ex. ads
   - links: can link to outside locations or images or pdf's
     - anchor <a> tag -  creates a hyperlink that can be clicked on to navigate to another webpage or a specific location within the same webpage.
     - href - where we want to link to 
     <a href="https://www.linkedin.com/in/ahmed-ibrahim-se/">Ahmed's LinkedIn</a>
     target="_blank" makes it to a new page
      <a href="page2.html" >Page 2</a> links to the html page that's in the same directory
      - image tag <img> - used to display an image on a web page
         <img src="image-source-url" alt="image-description"/>
         src attribute specifies the URL of the image file, while the alt attribute provides a textual description of the image
      - <img width="###" height="###" src="image-source-url" alt="image-description"/>
         -width and height defines the size of the image
      - video tag <video> - used to insert a video into a web page
         <video src="video-source-url" poster="image.png"autoplay loop controls></video>
         poster allows you to use a thumbnail
         autoplay plays immediately as the page is open
         loops plays as soon as it finishes
         controls allows you to play the video
      - lists:
         - unordered list <ul></ul>
            <li>Apples</li>
            ...
         - ordered list <ol></ol>
            <li>Apples</li>
            can specify type <ol type="A/a/i/1"> </ol>
         - description list <dl></dl>
            - <dl> represents the entire definition list
            - <dt> tag represents the term being defined
            - <dd> tag represents the definition of the term
               <dl>
                  <dt>HTML</dt>
                     <dd>HyperText Markup Language - the standard markup language used to create web pages.</dd>
  
                  <dt>CSS</dt>
                     <dd>Cascading Style Sheets - a stylesheet language used for describing the presentation of a document written in HTML.                 </dd>
  
                  <dt>JavaScript</dt>
                     <dd>A high-level programming language used to create interactive effects within web browsers.</dd>
               </dl>
         - container- set of tags that wrap other elements
         - elements are classified as block-level or inline-level, which determines how the element is displayed on a web page
         - Block- start on a new line and take up the full width Ex. <div>, <p>, <h1>-<h6>, <ul>, and <li>.
         - Inline- do not start on a new line and only take up as much width as necessary Ex. <a>, <span>, <img>, <strong>, and <em>
      -  input <input> -  allows the user to input data
         <input type="text"/>
         <input type="text" value="username"> - the user can enter their username. value displays somethings to the box before the user enters something
         <input type="password" value="password"> - creates a password box where the user's input is masked
         <input type="file" /> for inputting a file
         <input type="checkbox"/> a inputting a checkbox
         <input type="radio"/>a radio button
         <input type="submit"/>
         different input types: https://www.w3schools.com/tags/att_input_type.asp
      - test area <textarea><textarea/> - create a multi-line text input field where the user can enter a large amount of text.
      <textarea name="message" rows="4" cols="40"> Enter your message here.
      </textarea>
      - form <form> - allows users to enter and submit data to a server
         <form>
            <input type="submit"/>
         <form>
      iframe <iframe></iframe> - allows you to display content from another website or source within your own web page.
         <iframe src="https://www.example.com" width="500" height="500"></iframe>



```