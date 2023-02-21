import OpenGL.GL as gl
import OpenGL.GLU as glu
import pygame

vertices= (
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
    )

# group indexes of vertices

edges = (
    (0,1),
    (0,3),
    (0,4),
    (2,1),
    (2,3),
    (2,7),
    (6,3),
    (6,4),
    (6,7),
    (5,1),
    (5,4),
    (5,7)
    )

def Cube():
    gl.glBegin(gl.GL_LINES)
    for edge in edges:
        for vertex in edge:
            gl.glVertex3fv(vertices[vertex])
    gl.glEnd()


def main():
    pygame.init()
    display = (1920-100,1080-100)
    pygame.display.set_mode(display, pygame.DOUBLEBUF|pygame.OPENGL) # that means says to pygame that openlg and doublebuffer is using
    glu.gluPerspective(45, (display[0]/display[1]), 0.1, 50.0) # f(fov-y, h/w, range-znear-from-camera-wiev, range-zfar)
    gl.glTranslatef(0.0, 0.0, -5) # * matrix translation

    # key pressing detection
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
        gl.glRotatef(1, 3, 1, 1) # * rotation around vector defined xyz f(angle, x, y, z)
        gl.glClear(gl.GL_COLOR_BUFFER_BIT|gl.GL_DEPTH_BUFFER_BIT)
        Cube()
        pygame.display.flip() # refresh screen
        pygame.time.wait(10)      

main()

