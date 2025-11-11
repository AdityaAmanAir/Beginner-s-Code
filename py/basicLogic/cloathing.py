from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, PageBreak
from reportlab.lib.units import mm

doc_path = "mens_wearable_guide_complete.pdf"
doc = SimpleDocTemplate(doc_path, pagesize=A4, rightMargin=18*mm, leftMargin=18*mm, topMargin=18*mm, bottomMargin=18*mm)

styles = getSampleStyleSheet()
# Avoid redefining existing style names; use unique names
styles.add(ParagraphStyle(name='MyHeading1', fontSize=16, leading=20, spaceAfter=8))
styles.add(ParagraphStyle(name='MyHeading2', fontSize=13, leading=16, spaceAfter=6))
styles.add(ParagraphStyle(name='MyBody', fontSize=10.5, leading=14))
styles.add(ParagraphStyle(name='MyBullet', fontSize=10.5, leading=13, leftIndent=12))

content = []

# Title
content.append(Paragraph("Complete Men's Wearable Vocabulary — Exhaustive Guide", styles['MyHeading1']))
content.append(Paragraph("A simple, comprehensive PDF listing every common type of men's garment, footwear, accessory, and related terminology.", styles['MyBody']))
content.append(Spacer(1,8))

# Helper function to add sections
def add_section(title, items):
    content.append(Paragraph(title, styles['MyHeading2']))
    for it in items:
        content.append(Paragraph("• " + it, styles['MyBullet']))
    content.append(Spacer(1,6))

# Outerwear
outerwear = [
    "Overcoat (long formal coat, usually wool)",
    "Topcoat (shorter, lighter overcoat)",
    "Coat (general term)",
    "Trench Coat (waterproof, belted)",
    "Raincoat / Rain Jacket",
    "Parka (hip-length, often fur-lined hood)",
    "Anorak (pullover-style hooded coat)",
    "Puffer Jacket / Down Jacket (insulated)",
    "Quilted Jacket",
    "Fleece Jacket",
    "Pea Coat (navy-style wool coat)",
    "Pea Jacket (short pea coat styles)",
    "Field Jacket (military-inspired, multi-pocket)",
    "Bomber Jacket (short, fitted waist & cuffs)",
    "Varsity / Letterman Jacket",
    "Leather Jacket (biker, racer styles)",
    "Denim Jacket",
    "Windbreaker (lightweight, wind-resistant)",
    "Shacket / Overshirt (shirt-jacket hybrid)",
    "Over-shirt (light jacket worn like a shirt)",
    "Car Coat (short overcoat)",
    "Duster (very long coat)",
    "Cape / Cloak (rare, fashion item)"
]
add_section("Outerwear", outerwear)

# Tops / Body Clothes
tops = [
    "Dress Shirt (formal, collared, button-front)",
    "Button-Down Shirt (collar fastens with buttons)",
    "Casual Shirt (linen shirt, camp shirt, Cuban collar)",
    "Flannel Shirt",
    "Oxford Shirt",
    "Denim Shirt",
    "Polo Shirt",
    "T-Shirt (crewneck, V-neck, graphic tees)",
    "Henley Shirt",
    "Rugby Shirt",
    "Turtleneck / Rollneck",
    "Mock Neck",
    "Sweater (knitted pullover)",
    "Cardigan (button or zip front knit)",
    "Pullover (general knitwear)",
    "Crewneck Sweater",
    "V-neck Sweater",
    "Hoodie (hooded sweatshirt)",
    "Sweatshirt (without hood)",
    "Tank Top / Vest / A-shirt",
    "Thermal Shirt / Long Johns top",
    "Compression Shirt / Base Layer",
    "Waistcoat / Vest (casual or formal)",
    "Safari Shirt / Utility Shirt",
    "Cuban Collar Shirt / Camp Shirt",
    "Oversized Shirt / Longline Shirt",
    "Blouse (in unisex/high-fashion contexts)"
]
add_section("Tops / Upper-body Clothes", tops)

# Legwear
legwear = [
    "Jeans (skinny, slim, straight, bootcut, relaxed)",
    "Chinos",
    "Khakis",
    "Dress Trousers / Suit Trousers",
    "Suit Pants",
    "Corduroy Pants",
    "Linen Pants",
    "Cargo Pants",
    "Utility Pants",
    "Track Pants / Training Pants",
    "Joggers",
    "Sweatpants / Lounge Pants",
    "Shorts (casual, chino shorts, denim shorts)",
    "Bermuda Shorts",
    "Swim Shorts / Swim Trunks",
    "Overalls / Dungarees (bib overalls)",
    "Cropped Pants / Capris",
    "Leggings / Compression Pants (sports)",
    "Thermal Bottoms / Long Johns",
    "Trousers (generic British term)"
]
add_section("Legwear / Pants & Shorts", legwear)

# Footwear
footwear = [
    "Sneakers / Trainers (low-top, high-top, running shoes)",
    "Oxfords (formal laced shoes)",
    "Derby Shoes (open-laced formal shoes)",
    "Brogues (decorative perforations)",
    "Monk Strap Shoes (single/double buckle)",
    "Loafers (slip-on)",
    "Boat Shoes / Deck Shoes",
    "Moccasins",
    "Chelsea Boots (elastic-sided ankle boot)",
    "Chukka / Desert Boots (ankle boots with 2–3 eyelets)",
    "Dress Boots",
    "Work Boots (e.g., steel-toe)",
    "Hiking Boots",
    "Boots (general)",
    "Sandals",
    "Flip-flops / Thongs",
    "Espadrilles",
    "Slippers (indoor)",
    "Slides (casual slip-on sandal)"
]
add_section("Footwear", footwear)

# Accessories
accessories = [
    "Belt",
    "Tie (neck tie)",
    "Bow Tie",
    "Tie Clip / Tie Bar",
    "Cufflinks",
    "Pocket Square / Pocket Handkerchief",
    "Watch",
    "Bracelet",
    "Ring",
    "Necklace / Chain",
    "Hat (baseball cap, fedora, trilby, Panama)",
    "Beanie",
    "Cap subtypes (snapback, dad cap, trucker)",
    "Bucket Hat",
    "Beret",
    "Scarf",
    "Gloves (leather, wool, work gloves)",
    "Sunglasses",
    "Wallet",
    "Keychain / Keyring",
    "Umbrella",
    "Backpack",
    "Duffel Bag",
    "Messenger Bag / Crossbody Bag",
    "Briefcase",
    "Laptop Bag",
    "Gym Bag",
    "Face Mask (fashion / protective)",
    "Ear Muffs",
    "Suspenders / Braces",
    "Lapels / Lapel Pin",
    "Handkerchief (functional)"
]
add_section("Accessories", accessories)

# Underwear & Base Layers
underwear = [
    "Briefs",
    "Boxers",
    "Boxer Briefs",
    "Trunks",
    "Long Johns",
    "Thermal Underwear / Thermal Set",
    "Jockstrap",
    "Bikini Briefs",
    "G-string",
    "Compression Shorts",
    "Undershirt (crew neck, V-neck)",
    "Sleeveless Undershirt / Tank Vest"
]
add_section("Underwear & Base Layers", underwear)

# Formalwear
formalwear = [
    "Suit (two-piece: jacket + trousers)",
    "Suit Jacket / Blazer",
    "Dinner Jacket / Tuxedo Jacket",
    "Tuxedo (formal evening wear)",
    "Waistcoat (vest, part of three-piece suit)",
    "Cummerbund",
    "Tuxedo Trousers",
    "Evening Shirt / Dress Shirt",
    "Dress Shoes (patent leather for tuxedos)"
]
add_section("Formalwear", formalwear)

# Sportswear / Activewear / Swim
sportswear = [
    "Tracksuit (jacket + pants)",
    "Track Jacket",
    "Sports Jersey (team shirt)",
    "Gym Shorts",
    "Running Shorts",
    "Compression Gear (tops, bottoms)",
    "Swim Trunks / Swim Shorts",
    "Boardshorts",
    "Rash Guard",
    "Athletic Socks"
]
add_section("Sportswear / Activewear / Swim", sportswear)

# Workwear & Utility
workwear = [
    "Coveralls / Boiler Suit",
    "Overalls (work)",
    "Work Vest",
    "High-visibility Jackets / Safety Vest",
    "Uniform (military, service, corporate)",
    "Apron (cook, barber, workshop)",
    "Chef Jacket",
    "Mechanic's Coveralls"
]
add_section("Workwear & Utility", workwear)

# Sleepwear & Loungewear
sleepwear = [
    "Pyjamas / Pajama Set",
    "Nightshirt",
    "Bathrobe / Dressing Gown",
    "Lounge Pants",
    "Sleep Shorts",
    "Slippers (indoor footwear)"
]
add_section("Sleepwear & Loungewear", sleepwear)

# Headwear (detailed)
headwear = [
    "Baseball Cap",
    "Trucker Cap",
    "Snapback",
    "Dad Cap",
    "Fedora",
    "Trilby",
    "Panama Hat",
    "Beanie / Watch Cap",
    "Flat Cap / Newsboy Cap",
    "Bucket Hat",
    "Beret",
    "Sun Hat"
]
add_section("Headwear", headwear)

# Bags & Travel
bags = [
    "Backpack",
    "Daypack",
    "Messenger Bag",
    "Crossbody Bag",
    "Duffel Bag",
    "Weekender Bag",
    "Briefcase",
    "Laptop Bag",
    "Travel Wallet",
    "Waist Bag / Fanny Pack"
]
add_section("Bags & Travel", bags)

# Jewelry & Small Accessories
jewelry = [
    "Cufflinks",
    "Tie Pin",
    "Tie Clip",
    "Lapel Pin",
    "Bracelet",
    "Ring",
    "Necklace / Chain",
    "Earrings (in some fashion contexts)"
]
add_section("Jewelry & Small Accessories", jewelry)

# Fabrics, Patterns & Terminology
terminology = [
    "Fabrics: cotton, wool, linen, denim, leather, suede, polyester, nylon, silk, flannel, corduroy, tweed",
    "Patterns: solid, striped, plaid / tartan, checked, herringbone, camo, floral, paisley, geometric, printed",
    "Fits: slim, skinny, regular, relaxed, tapered, tailored",
    "Necklines: crewneck, V-neck, scoop neck, henley placket, turtleneck",
    "Sleeve types: short sleeve, long sleeve, 3/4 sleeve, raglan sleeve",
    "Pant rises: low-rise, mid-rise, high-rise",
    "Lining, interlining, liningless",
    "Hem types: cuffed / turned-up, raw hem, tapered hem",
    "Layers / layering (base layer, mid layer, outer layer)",
    "Care terms: dry clean, machine wash, hand wash, tumble dry, iron at low/medium/high"
]
add_section("Fabrics, Patterns & Common Terminology", terminology)

# Fit & Sizing Tips (short)
fit_sizing = [
    "Fit guides: measure chest, waist, hips, inseam, sleeve length, neck",
    "Try size charts for brands (sizes vary by brand & region)",
    "Alterations: hemming pants, tapering, taking in/out seams"
]
add_section("Fit & Sizing Tips (brief)", fit_sizing)

# Closing note
content.append(Spacer(1,8))
content.append(Paragraph("Notes:", styles['MyHeading2']))
content.append(Paragraph("This guide aims to be comprehensive for common and widely used men's garments, footwear, accessories, and related terminology. Items included cover casual, formal, active, work, and specialty wear. Niche or historical items (very rare/vintage) may not be exhaustively listed but most practical modern categories are covered.", styles['MyBody']))
content.append(Spacer(1,6))
content.append(Paragraph("Prepared: Full exhaustive list generated on request.", styles['MyBody']))

# Build PDF
doc.build(content)

print(f"PDF created successfully: {doc_path}")