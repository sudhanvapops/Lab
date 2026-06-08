// 7. Install an Open Source NoSQL Database MongoDB & perform basic CRUD (Create, Read, Update & Delete) operations. Execute MongoDB basic queries using CRUD operations.

//1. Create or switch to database
use StudentDB


// 2. CREATE (Insert Documents)

// Adds student documents to the students collection.

// Insert one student record
db.students.insertMany([
    {
        _id: 1,
        RollNo: 1,
        Name: "Rahul",
        Age: 20,
        Course: "BCA"
    },
    {
        _id: 2,
        RollNo: 2,
        Name: "Anu",
        Age: 21,
        Course: "BSc"
    }
])


// 3. READ (Retrieve Documents)

// Retrieves all documents from the collection.

// Display all records
db.students.find()


// 4. UPDATE (Modify Documents)

// Update Age of student with RollNo 1
db.students.updateOne(
    { RollNo: 1 },
    { $set: { Age: 22 } }
)


// 5. READ Again (Verify Update)
db.students.find()


// 6. DELETE (Remove Document)
// Delete student with RollNo 2
db.students.deleteOne(
    { RollNo: 2 }
)


// 7. READ Again (Verify Delete)
db.students.find()