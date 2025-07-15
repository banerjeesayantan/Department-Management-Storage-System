Department-Management-Storage-System
"Organize, track, and manage your department’s products easily  with a lightweight, file‑based C++ system."


✅ What problem does it solve?
- Small businesses, college departments, or internal teams often struggle with:
-  Disorganized spreadsheets
- Manual stock tracking
- No record of sales history
- No simple interface to update or view products

##This system digitizes and centralizes all product and sales data, so it’s easier to manage stock, record sales, and view saved items.

✅ Benefits:
- Add, edit, delete products with clear product details
- File-based data persistence (products.txt keeps data between runs)
- Buy products (updates stock & sold count)
- Save items for later (user wishlist)
- Quickly view product lists with real-time updates

##Lightweight: no external database; runs on any standard C++ compiler.


✅ Where you can use this code:
- College department stores (stationery, books, lab items).
- Small retail shops needing an offline stock manager.
- Backend prototype for inventory modules in a bigger system.

##Learning project to understand file handling, OOP, and menus in C++.

✅ Classes:
- optionAdmin: add/edit/delete products, see stock & sold count.
- optionUser: view products, buy items (updates stock & sold), save items.

✅ Data:
- Stored in plain text: products.txt.
- On startup: loadProductsFromFile() reads data.
- On changes: saveProductsToFile() writes data.

✅ User interface:

Text-based console menus:
- Admin: add/edit/delete/list products
- User: browse, buy, view saved items


✅ When you start / open the system:
The program loads all saved products from products.txt into memory.

You’ll see the main menu:
1. Admin
2. User
3. Exit

✅ Choose:
- Admin → for managing products (add, edit, delete, view)
- User → for browsing products, buying items, saving items
- Exit → to close the system

✅ Admin can:
- Add new products (name, ID, company, price, stock)
- Edit product details (if data changes)
- Delete products (if discontinued)
- View full product list (with stock & sold count)

##Every change automatically updates products.txt so data is never lost.

✅ User can:
- View all available products (with price & stock)
- Buy products (updates stock & sold number)
- Save items for later (personal wishlist)
- View saved items anytime

✅ While the system is running:
- All data changes are kept in memory immediately.
- After changes, data is saved back to products.txt.

✅ When you exit / turn off the system:
- All your changes stay safe in products.txt.
- Next time you run the program, it reloads the saved data automatically — you continue where you left off.

✨ In short:
- Fully offline, works on any PC/laptop with a C++ compiler.
- Data is stored in a simple text file (products.txt).
- No database or network needed — perfect for small shops or departments.
- Users can add, edit, delete, view, buy, or save products easily.


#"A simple C++ product & stock management system built to help small departments or shops organize products, track sales, and save favorite items with real-time file storage."

  
Written by - Sayantan Banerjee.
