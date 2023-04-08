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