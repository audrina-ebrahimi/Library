
# Library Management System

This is my final project for the advanced programming course at the University of Isfahan.
It has been written with Qt using QWidgets.
It is provided users with a Devil theme GUI for two genders and a login system with two types of permissions.

<img src="https://user-images.githubusercontent.com/82520498/187414402-63620776-fdef-4ada-b093-b0b050936b4b.png" width="700" height="400" alt="screenshot of Main page">



## Usage

For running and modifying this project you should have installed Qt Creator on your system.
Then open `library.pro` and click on the build and run button.

Also you can use the executable file from here.
## Examples of use 

- Signup

    In this panel, you can signup with your preferred username and password.
    <details> 
    <summary> Screenshot </summary>
        <img src="https://user-images.githubusercontent.com/82520498/187411471-86a1f438-aaef-4b28-a32f-b29d8293705c.png" width="700" height="400" alt="screenshot of Signup page">
    </details>
    


- Login

    After signup, you can use your username and password to log in.
    <details> 
    <summary> Screenshot </summary>
        <img src="https://user-images.githubusercontent.com/82520498/187413977-5542cbc6-47b1-4075-93c4-51ccdd6a3482.png" width="700" height="400" alt="screenshot of Login page">
    </details>

- Admin Dashboard 

    First of all, there's an admin panel with username `admin` and password `admin`. If you signup and login with this credential you can easily access the admin       dashboard.
    
    <img src="https://user-images.githubusercontent.com/82520498/187421354-ce7507ee-b1c9-42a4-a71b-e49621202c83.png" width="700" height="400" alt="screenshot of Admin Dashboard page">


    This panel has below features:

    - Add, Edit and Delete a Book
    
        <details> 
        <summary>Add Book page</summary>
            Write the book's needed information and press the "Add" button.
            <img src="https://user-images.githubusercontent.com/82520498/187422100-e91550e5-676d-40ce-899d-7abc6eba4e19.png" width="700" height="400" alt="screenshot of Add Book page">
        </details>
        
        <details> 
        <summary>Edit Book page</summary>
            First, choose a book to edit.
            </br>
            <img src="https://user-images.githubusercontent.com/82520498/187435355-e8c2a323-140e-43af-bec4-65ea23db1d7a.png" width="700" height="400" alt="screenshot of Edit Book page">
            </br>
            Change any part you want and press the "Save changes" button.
            <img src="https://user-images.githubusercontent.com/82520498/187423485-c0736c4a-6321-462c-bddd-3d8e894d3054.png" width="700" height="400" alt="screenshot of Edit Book page">
        </details>
        
        <details> 
        <summary>Delete Book page</summary>
            Select the book you want to delete and press the "Send this book to hell" button.
            <img src="https://user-images.githubusercontent.com/82520498/187424304-8d7474c2-9ad4-4f34-9e1c-d83baaf25c98.png" width="700" height="400" alt="screenshot of Delete Book page"> 
        </details>
        

    - Group Books

        In this part you can add, edit and delete a group for books.
        
        <img src="https://user-images.githubusercontent.com/82520498/187425523-d7d4c15f-2d49-4d31-99f0-3790bf02559a.png" width="700" height="400" alt="screenshot of Group Book page">
        
        <details> 
        <summary>Add Group page</summary>
            Select the book you want to add in a group, choose a name for the group and press the "Add this group" button.
            <img src="https://user-images.githubusercontent.com/82520498/187425807-0bfb7769-0b6e-4806-b3b9-18878dc63ad9.png" width="700" height="400" alt="screenshot of Add Group page"> 
        </details>
        
        <details> 
        <summary>Edit Group page</summary>
            Select the book you want to have in group, you can choose a new name for the group and press the "Edit this group" button.
            <img src="https://user-images.githubusercontent.com/82520498/187426176-e1a1977f-257f-4137-bb83-468a42b8f8ea.png" width="700" height="400" alt="screenshot of Edit Group page">
        </details>
        
        **Delete Group**: To delete a group just select the group name and press the "Delete" button.
        
        *note*: To see the changes you made in the dashboard you have to press the "Refresh List" button. 

    - View Book List and Members List
   
        <details> 
        <summary>View Book List page</summary>
            Here is the list of all books you can search by any parameter and see the results.
            <img src="https://user-images.githubusercontent.com/82520498/187427780-7ca387a7-6264-4f62-9bfc-665dfdc943ed.png" width="700" height="400" alt="screenshot of View Book List page">
        </details>
        
        <details> 
        <summary>View Member List page</summary>
            Here is the list of all members you can search their name, see the results, and delete them if you want.
            <img src="https://user-images.githubusercontent.com/82520498/187428360-42b17085-ac51-4872-bb49-ae5531b33b18.png" width="700" height="400" alt="screenshot of View Member List page">
        </details>
        

    - Members Situation

        In this part, you can see the members and their borrowed books. If the expiration time of a book is close the row color will be yellow and if it is passed the color will be red.
        <details> 
        <summary>Screenshot</summary>
            <img src="https://user-images.githubusercontent.com/82520498/187429225-223ff6d6-84d6-4b86-93f3-569deed44d78.png" width="700" height="400" alt="screenshot of Members Situation List page">          
        </details>

- User Dashboard

    In this part, you can choose between a girl and boy dashboard. Technically, they don't differ in basics except for their backgrounds.
    
     <img src="https://user-images.githubusercontent.com/82520498/187432288-8f1bb2dc-2d32-4165-afb0-d2986c389211.png" width="700" height="400" alt="screenshot of Choose Gender page">

     <details>
     <summary>Girl Dashboard</summary>
        <img src="https://user-images.githubusercontent.com/82520498/187433532-f5f8eedc-9a7f-41cc-9a78-70ac2716b44d.png" width="700" height="400" alt="screenshot of Girl Dashboard page">
      </details>
      <details>
      <summary>Boy Dashboard</summary>
        <img src="https://user-images.githubusercontent.com/82520498/187434107-18f20b2b-c484-42a1-8b7e-593ca4a09502.png" width="700" height="400" alt="screenshot of Girl Dashboard page">
      </details>

    User panel has below features:

    - View Book List
    
        Here is the list of all books you can search by any parameter and see the results. 
        <details>
        <summary>Screenshot</summary>
            <img src="https://user-images.githubusercontent.com/82520498/187434505-b63afa0d-d155-4bc2-a6ac-5456c36545ea.png" width="700" height="400" alt="screenshot of Books List page">
        </details>
        
    - Get of Return Books

        <details>
        <summary>Get Books</summary>
            Select any book you want to borrow and press the "Get this book" button.
            </br>
            Two factors won't let you borrow a book: First, you can't borrow any book when you have an expired book in your account. Second, you can't borrow more than 5 books.
            <img src="https://user-images.githubusercontent.com/82520498/187436591-e54b4459-7500-44bf-96da-4cdb2adf33e8.png" width="700" height="400" alt="screenshot of Get Book page">
               
        </details>
        
        <details>
        <summary>Return Books</summary>
            Select the book you want to return and press the "Return this book" button. If the expiration time of a book is close the row color will be yellow and if it is passed the color will be red.
            <img src="https://user-images.githubusercontent.com/82520498/187437321-44cffdb3-573b-4cb7-ada8-ef69a5da9f20.png" width="700" height="400" alt="screenshot of Return Book page">
        </details>

    - Private Room
    
        This part does't do any special thing. Just returns a massage that says "This item isn't available in your country".




    

