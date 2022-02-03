# ----------------------------
# Makefile Options
# ----------------------------

NAME = Render
ICON = icon.png
DESCRIPTION = "Render a thing"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
