const coords = [
  {
    id: "Amphitheater",
    imagePath: "./Images/1.jpg",
    title: "Amphitheater",
    description:
      "Commonly used for performances, lectures, and cultural events, an outdoor venue with terraced seating.",
  },

  {
    id: "Banda Kawayan, Sining Lahi Headquarters",
    title: "Banda Kawayan, Sining Lahi Headquarters",
    description:
      "Commonly used for performances, lectures, and cultural events, an outdoor venue with terraced seating.",
  },

  {
    id: "Building and Grounds Maintenance Office",
    title: "Building and Grounds Maintenance Office",
    description:
      "Responsible for maintaining as well as upkeep of the university's buildings and outdoor areas, assuring a safe and well-maintained environment for students, faculty, and staff.",
  },

  {
    id: "Catwalk",
    title: "Catwalk",
    imagePath: "./Images/4.jpg",
    description:
      "It is a pedestrian route, enabling university students, teachers, and other employees to move between buildings and areas.",
  },

  {
    id: "Centennial Monument",
    title: "Centennial Monument",
    imagePath: "./Images/5.jpg",
    description:
      "A monument was built to honor the Polytechnic University of the Philippines' centennial. It may represent the institution's history, accomplishments, or values.",
  },

  {
    id: "Charlie del Rosario Student Development Center",
    imagePath: "./Images/6.jpg",
    title: "Charlie del Rosario Student Development Center",
    description:
      "A facility committed to encouraging the academic, social, and personal development of PUP students. It may provide counseling, career guidance, and leadership development.",
  },

  {
    id: "East Gate",
    imagePath: "./Images/7.jpg",
    title: "East Gate",
    description:
      "One of the campus entrances on the eastern edge of the PUP campus.",
  },

  {
    id: "Flag Pole",
    imagePath: "./Images/8.jpg",
    title: "Flag Pole",
    description:
      "It often serves as a symbol of national pride during flag ceremonies and national celebrations.",
  },

  {
    id: "Grandstand",
    imagePath: "./Images/9.jpg",
    title: "Grandstand",
    description:
      "A huge, elevated seating area with an excellent view of the surrounding area, typically found in sports stadiums or event venues.",
  },

  {
    id: "Gymnasium",
    imagePath: "./Images/10.jpg",
    title: "Gymnasium",
    description:
      "A building that is equipped for sports and physical exercise, including basketball, volleyball, and other indoor sports.",
  },

  {
    id: "Interfaith Chapel",
    imagePath: "./Images/11.jpg",
    title: "Interfaith Chapel",
    description:
      "An area of devotion that welcomes people of diverse religious backgrounds, promotes diversity, and offers a tranquil space for prayer, meditation, and reflection.",
  },

  {
    id: "Laboratory High School",
    imagePath: "./Images/12.jpg",
    title: "Laboratory High School",
    description:
      "An area of devotion that welcomes people of diverse religious backgrounds, promotes diversity, and offers a tranquil space for prayer, meditation, and reflection.",
  },

  {
    id: "Lagoon",
    imagePath: "./Images/13.jpg",
    title: "Lagoon",
    description:
      "A tiny pond of water, typically with encircling landscaping, functions as a decorative element on campus and provides a tranquil and picturesque setting.",
  },

  {
    id: "Main Building – Dome",
    imagePath: "./Images/14.jpg",
    title: "Main Building – Dome",
    description:
      "A conspicuous architectural element of PUP's main building, characterized by a structure in the form of a dome. It may contain administrative offices, classrooms, or additional facilities.",
  },

  {
    id: "Main Building - East Wing",
    imagePath: "./Images/15.jpg",
    title: "Main Building - East Wing",
    description:
      "The east wing of the primary facility at PUP, which may contain classrooms, laboratories, or administrative offices.",
  },

  {
    id: "Main Building - North Wing",
    imagePath: "./Images/16.jpg",
    title: "Main Building - North Wing",
    description:
      "The north wing of the primary facility at PUP, which may contain classrooms, laboratories, or administrative offices.",
  },

  {
    id: "Main Building - South Wing",
    title: "Main Building - South Wing",
    description:
      "The south wing of the primary facility at PUP, which may contain classrooms, laboratories, or administrative offices.",
  },

  {
    id: "Main Building - West Wing",
    imagePath: "./Images/18.jpg",
    title: "Main Building - West Wing",
    description:
      "The west wing of the primary facility at PUP, which may contain classrooms, laboratories, or administrative offices.",
  },

  {
    id: "Main Gate",
    imagePath: "./Images/19.jpg",
    title: "Main Gate",
    description:
      "The principal entrance to the PUP campus, which frequently features prominent signage or architecture.",
  },

  {
    id: "Nemesio E. Prudente Freedom Park",
    imagePath: "./Images/20.jpg",
    title: "Nemesio E. Prudente Freedom Park",
    description:
      "Former university president Nemesio E. Prudente is honored by a location on the PUP campus that bears his name. It may function as a gathering place or recreational area for students and visitors.",
  },

  {
    id: "Ninoy Aquino Library and Learning Resources Center",
    imagePath: "./Images/21.jpg",
    title: "Ninoy Aquino Library and Learning Resources Center",
    description:
      "The Benigno 'Ninoy' Aquino Jr. Library and Resource Center at PUP was named in his honor. It provides access to a vast assortment of educational materials, such as books, journals, and digital resources.",
  },

  {
    id: "Open Court",
    imagePath: "./Images/22.jpg",
    title: "Open Court",
    description:
      "Outdoor space with a concrete court surface, frequently used for sports and recreation such as basketball, volleyball, and tennis.",
  },

  {
    id: "CNFS Building",
    imagePath: "./Images/23.jpg",
    title: "CNFS Building",
    description:
      "Abbreviation for a particular structure or facility on the PUP campus.",
  },

  {
    id: "Oval Open Field",
    imagePath: "./Images/24.jpg",
    title: "Oval Open Field",
    description:
      "Oval-shaped open space typically used for outdoor activities, athletics, or events.",
  },

  {
    id: "P.E. Building",
    imagePath: "./Images/25.jpg",
    title: "P.E. Building",
    description:
      "A facility devoted to physical education and sports-related activities, such as indoor sports, fitness training, and exercise classes.",
  },

  {
    id: "Pasig River",
    imagePath: "./Images/26.jpg",
    title: "Pasig River",
    description:
      "A essential Philippine river that travels close to the PUP campus. It is a significant waterway and geographical feature of the region.",
  },

  {
    id: "Pasig River Ferry (Sta. Mesa Station)",
    imagePath: "./Images/27.jpg",
    title: "Pasig River Ferry (Sta. Mesa Station)",
    description:
      "On the Pasig River, close to the PUP campus, is a ferry terminal. Along the river, it provides conveyance services to commuters.",
  },

  {
    id: "Access Road",
    imagePath: "./Images/28.jpg",
    title: "Access Road",
    description:
      "A road or path that provides access to or departure from the PUP campus, linking it to its environs or major transportation routes.",
  },

  {
    id: "Public Restroom",
    imagePath: "./Images/29.jpg",
    title: "Public Restroom",
    description:
      "On the PUP campus, a facility with restrooms, basins, and other amenities that is open to the public.",
  },

  {
    id: "PUP Linear Park",
    imagePath: "./Images/30.jpg",
    title: "PUP Linear Park",
    description:
      "The PUP Linear Park is presumably a landscaped location on campus that provides recreational opportunities and vegetation.",
  },

  {
    id: "PUP Mural and the Shrine of Heroism",
    imagePath: "./Images/31.jpg",
    title: "PUP Mural and the Shrine of Heroism",
    description:
      "A mural or work of art on display at PUP that depicts significant events, historical figures, or cultural aspects. The Shrine of Heroism may refer to a memorial or monument commemorating national leaders or notable contributors.",
  },

  {
    id: "PUP Obelisk (and the Mabini Monument)",
    imagePath: "./Images/32.jpg",
    title: "PUP Obelisk (and the Mabini Monument)",
    description:
      "A tall, slender, four-sided monument with a pointed tip is an obelisk. The PUP Obelisk may be a conspicuous campus landmark. The Mabini Monument is likely a distinct monument dedicated to the Filipino revolutionary and statesman Apolinario Mabini.",
  },

  {
    id: "PUP Property Building and Motorpool",
    title: "PUP Property Building and Motorpool",
    description:
      "A structure or facility dedicated to the administration of the university's property, facilities, and vehicles. It may consist of administrative offices, maintenance facilities, and parking lots.",
  },

  {
    id: "PUP Pylon",
    imagePath: "./Images/34.jpg",
    title: "PUP Pylon",
    description:
      "A pylon is a towering, vertical structure used as a landmark or as a support for different installations. ",
  },

  {
    id: "Sampaguita Building",
    imagePath: "./Images/35.jpg",
    title: "Sampaguita Building",
    description:
      "A structure on the PUP campus that is named after the Sampaguita flower, the national emblem of the Philippines. Its function or purpose would depend on its classification within the university.",
  },

  {
    id: "Student Pavilion",
    imagePath: "./Images/36.jpg",
    title: "Student Pavilion",
    description:
      "A covered outdoor area or structure intended to provide students with a space for informal gatherings, events, or recreational activities.",
  },

  {
    id: "Swimming Pool",
    imagePath: "./Images/37.jpg",
    title: "Swimming Pool",
    description:
      "A facility outfitted with a pool for swimming and aquatic activities, which is frequently utilized for physical education classes, training, and recreation.",
  },

  {
    id: "Tennis Open Court",
    imagePath: "./Images/38.jpg",
    title: "Tennis Open Court",
    description:
      "A tennis court designed specifically for outdoor play, with a hard court surface and appropriate markings.",
  },

  {
    id: "Water Tank",
    imagePath: "./Images/39.jpg",
    title: "Water Tank",
    description:
      "A large container or reservoir used to store water for various purposes, including irrigation, firefighting, and campus water supply.",
  },

  {
    id: "West Gate",
    imagePath: "./Images/40.jpg",
    title: "West Gate",
    description:
      "One of the campus entrances is on the western edge of the PUP campus.",
  },
];
