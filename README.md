# LCR

A C++ object-oriented application designed to manage a volunteer-driven 
platform. The system facilitates the registration and tracking of 
organization members, coordinates repair targets, logs available 
materials/resources, and executes restoration tasks using a templated 
workflow system.


1. FEATURES

* User & Platform Management: Register organizations, organizers, 
  and volunteers.
* Target Tracking: Manage structural repairs categorized into Buildings 
  and Roads.
* Resource Allocation: Inventory control for consumable items split 
  into Hygiene Materials and Construction Tools.
* Templated Task Architecture: Programmatic validation and execution 
  of custom repair tasks (RestorationTask<T>) which manages target 
  types dynamically.
* Persistent Storage: Export platform records (Organizers, Volunteers, 
  Targets, Resources) to separate plain text flat files (.txt).



2. CLASS HIERARCHY & ARCHITECTURE

The project relies heavily on Object-Oriented Programming (OOP) concepts 
such as inheritance, polymorphism, abstract classes, and encapsulation.

A. Core Base Structure
   - OrganizationEntity (Abstract Base Class): Standardizes stream 
     input/output interfaces (Input / Output) across all sub-entities. 
     Contains a central heap helper function 'allocateAndCopy' to safely 
     allocate memory dynamically for char* C-style string fields.

B. People & Entities (Person Subtree)
   - Person: Houses basic demographic criteria like name elements 
     (FirstName, LastName) and Age. Safely implements the Rule of Three 
     (Copy Constructor, Assignment Operator, Destructor) to handle 
     heap pointers.
   - Organizer (Inherits from Person): Automatically assigns individual 
     identification numbers through an internal static identifier counter 
     tracker.
   - Organization (Inherits from Organizer): Expands on the 
     organizational identity by maintaining an active address record 
     string and balance metrics (Money).
   - Volunteer (Inherits from Person): Handles unique volunteer identities, 
     tracks individual financial donations, and increments experiential 
     scoring levels (Points) upon successful assignment fulfillments.

C. Restoration Objectives (Target Subtree)
   - Target (Abstract Base Class): Conceptual foundation for a project 
     site consisting of dynamic physical location descriptions and 
     target context metadata.
   - Building (Inherits from Target): Refines target details specifically 
     to manage infrastructure architecture fields (BuildingType).
   - Road (Inherits from Target): Quantifies restoration assignments 
     focusing explicitly on pavement/transit distances (LengthKm).

D. Supply Control (Resource Subtree)
   - Resource: Tracks platform equipment asset names alongside existing 
     numeric inventories (Quantity). Includes functional operations like 
     use(qty) to accurately scale downstream warehouse states.
   - Hygiene (Inherits from Resource): Tracks sanitary condition settings 
     via boolean verification variables (IsSterile).
   - Tool (Inherits from Resource): Includes context fields explaining 
     operations deployment descriptions (Usage).

E. Automated Workflow Tasks
   - RestorationTask<T_Target> (Generic Template): Binds a task target 
     (T_Target*), a generic Volunteer*, and a necessary asset inventory 
     requirement supply marker (Resource*) into an executable task unit.



3. COMPILATION

The project uses standard modern C++ compilation dependencies. You can 
compile the project using any modern standard C++ CLI wrapper framework 
or standard IDE workspace (like Visual Studio, CLion, or GCC).

Manual Compilation Command via Terminal (GCC/G++):
g++ -std=c++17 Main.cpp Person.cpp Organizer.cpp Organization.cpp Volunteer.cpp Target.cpp Building.cpp Road.cpp Resource.cpp Hygiene.cpp Tool.cpp -o VolunteerPlatform



4. SYSTEM EXECUTION FLOW

Upon launching VolunteerPlatform, the program loads a loop-based console 
UI dashboard divided into dedicated processing segments:

A. Platform Management
   Enables the interactive construction of instances to register objects 
   into active programmatic vectors:
   - Organizers / Organizations
   - Volunteers
   - Repair Targets (Buildings / Roads)
   - Resources (Hygiene Kits / Tools)

B. Task Execution Engine
   Combines runtime parameters into an instance of RestorationTask.
   - The system performs inventory stock checks (qty > resource->getQuantity()). 
   - If inventory is insufficient, it throws a runtime_error, halting 
     execution and notifying the coordinator.
   - On a successful run, the resource inventory is deducted and the 
     volunteer receives +50 experience points.

C. Data File Synchronization
   Exports state collections from working program memory into cleanly 
   labeled flat .txt data files for historical logging.



5. FILE DIRECTORY STRUCTURE

├── Main.cpp                 # Main loop routing dashboard & file stream methods
├── Libraries.h              # Centralized header references and standard imports
├── OrganizationEntity.h     # Abstract base node containing memory utilities
├── Person.h / .cpp          # Structural properties for personal metadata
├── Organizer.h / .cpp       # ID allocation logic for organizers
├── Organization.h / .cpp    # Financial bookkeeping tracking
├── Volunteer.h / .cpp       # Experience tallying and donation details
├── Target.h / .cpp          # Core abstract framework for repair locations
├── Building.h / .cpp        # Property sub-type characteristics 
├── Road.h / .cpp            # Mileage measurements for transit paths
├── Resource.h / .cpp        # Shared structures for platform supplies
├── Hygiene.h / .cpp         # Specialized medical/sanitary validation
├── Tool.h / .cpp            # Asset machinery classifications
└── Tasks.h                  # Template definition for restoration actions
