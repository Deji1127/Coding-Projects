- You can add css by creating an external css file and linking it to the html file
   <link rel="stylesheet" type="text/css" href="filename.css">
- You can import google fonts into html file
  - first put the link into the header section of the html file
      <link href="https://fonts.googleapis.com/css2?family=Lobster&display=swap" rel="stylesheet">
   - Then have font you want in css
     font-family: "Lobster", cursive; 
- Styles <style></style> - visual appearance of an HTML document that allow you to control the font, color, size, layout, and other visual aspects
  - Inline styles - allow you to apply CSS styles directly to individual HTML elements using the style attribute. useful when you want to apply a specific style to a single element without affecting the rest of the page.
     <p style="color: red; font-size: 24px;">This text is styled with inline styles.</p>
  - Style block - allows you to define CSS styles for multiple elements in a single location 
     <style>
          h2 {color: blue;}
      </style>
      this makes every h2 tag blue
- Classes - reuseable styles that can be added to html element; a way to apply styles to multiple HTML elements using a single name; done by using a period
   .black-text{
        color: green;
        font-size: 30px;
    }
    <div class="black-text">
    - color - controls the color
       color: purple;
    - font size - controls the size of the font
       font-size: 10px;
    - font family 
       font-family: 'Courier New', Courier, monospace;
- Borders 
   border: 2px solid black;
  - use border radius to make the border more rounded 
     border-radius: 10px;
  - Set different roundedness for each corner 
      border-top-left-radius: 20px;
      border-top-right-radius: 10px;
      border-bottom-left-radius: 30px;
      border-bottom-right-radius: 40px
- id - can be added to an HTML element to uniquely identify it within the document  
- padding- used to create space within an element, between its content and its border. applied to all four sides of an element (top, right, bottom, and left), or individually as padding-top, padding-right, padding-bottom, and padding-left. The padding value is added to the element's width and height, which can affect the element's layout and positioning.
- border - used to create space around an element, outside its border. applied to all four sides of an element (top, right, bottom, and left), or individually as margin-top, margin-right, margin-bottom, and margin-left. The margin value is not added to the element's width and height, which means it doesn't affect the element's layout or positioning, but rather the space around it.
- background image - make an image the background
   background-image
