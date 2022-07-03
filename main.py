import pygame

WINWIDTH = 640 
WINHEIGHT = 480 

GRIDSIZE = 35
LINEWIDTH = 8

BGCOLOR = (255, 255, 255)
FGCOLOR = (255, 0, 0)

def draw_grid(screen):
  for g in range(0, GRIDSIZE*GRIDSIZE, LINEWIDTH*2):
    for w in range(LINEWIDTH):
      for x in range(WINWIDTH):
        screen.set_at((x, w+g), FGCOLOR)
      for y in range(WINHEIGHT):
        screen.set_at((w+g, y), FGCOLOR)

def render():
  running = True
  event = pygame.event
  while running:
    pygame.display.flip()
    
    for event in pygame.event.get():
      running = not event.type is pygame.KEYDOWN


def main():
  
  screen = pygame.display.set_mode((WINWIDTH, WINHEIGHT))
  screen.fill(BGCOLOR)
  
  draw_grid(screen)
  render()


if __name__ == '__main__':
    main()
