Department-Management-Storage-System
"Organize, track, and manage your department’s products easily  with a lightweight, file‑based C++ system."


✅ What problem does it solve?
- Small businesses, college departments, or internal teams often struggle with:
-  Disorganized spreadsheets
- Manual stock tracking
- No record of sales history
- No simple interface to update or view products

##This system digitizes and centralizes all product and sales data, so it’s easier to manage stock, record sales, and view saved items.

🌟 Benefits:
- Add, edit, delete products with clear product details
- File-based data persistence (products.txt keeps data between runs)
- Buy products (updates stock & sold count)
- Save items for later (user wishlist)
- Quickly view product lists with real-time updates

##Lightweight: no external database; runs on any standard C++ compiler

Where you can use this code:
- College department stores (stationery, books, lab items)
- Small retail shops needing an offline stock manager
- Backend prototype for inventory modules in a bigger system

##Learning project to understand file handling, OOP, and menus in C++.

🧩 System & Architecture (explained simply):

┌─────────────┐        ┌─────────────┐
│ Admin Menu  │◀─────▶│ User Menu   │
└─────────────┘        └─────────────┘
        │                    │
        ▼                    ▼
   ┌───────────┐       ┌────────────┐
   │ optionAdmin│       │ optionUser │
   └───────────┘       └────────────┘
        │                    │
        └─────────────┬──────┘
                      ▼
               ┌────────────┐
               │ products[] │ (Array of products)
               └────────────┘
                      │
                      ▼
          ┌────────────────────┐
          │ products.txt file  │ (Save/Load products)
          └────────────────────┘



✅ Classes:
- optionAdmin: add/edit/delete products, see stock & sold count.
- optionUser: view products, buy items (updates stock & sold), save items.

✅ Data:
- Stored in plain text: products.txt.
- - On startup: loadProductsFromFile() reads data.
- On changes: saveProductsToFile() writes data.

✅ User interface:

Text-based console menus:
- Admin: add/edit/delete/list products
- User: browse, buy, view saved items



✨ In short:
--> "A simple C++ product & stock management system built to help small departments or shops organize products, track sales, and save favorite items with real-time file storage."

Written by - Sayantan Banerjee.
