import tkinter as tk
from tkinter import messagebox
from tkinter import simpledialog

class DFSVisualizer:
    def __init__(self, root):
        self.root = root
        self.root.title("Depth-First Search (DFS) Visualizer")
        self.graph = {}
        self.traversal_order = []
        
        # GUI Elements
        self.canvas = tk.Canvas(self.root, width=400, height=400, bg="white")
        self.canvas.pack(pady=20)
        
        self.info_label = tk.Label(self.root, text="Click on canvas to add nodes and edges.")
        self.info_label.pack()
        
        self.start_button = tk.Button(self.root, text="Start DFS", command=self.start_dfs)
        self.start_button.pack(pady=5)
        
        self.reset_button = tk.Button(self.root, text="Reset", command=self.reset)
        self.reset_button.pack(pady=5)
        
        self.nodes = {}
        self.edges = []
        
        self.canvas.bind("<Button-1>", self.add_node)
    
    def add_node(self, event):
        node_name = simpledialog.askstring("Input", "Enter node name:")
        
        if node_name and node_name not in self.graph:
            x, y = event.x, event.y
            self.nodes[node_name] = (x, y)
            self.graph[node_name] = []
            
            self.canvas.create_oval(x-15, y-15, x+15, y+15, fill="lightblue")
            self.canvas.create_text(x, y, text=node_name)
            
            self.add_edges(node_name)
        else:
            messagebox.showwarning("Warning", "Node already exists or invalid name.")
    
    def add_edges(self, node_name):
        for other_node in self.graph:
            if other_node != node_name:
                if messagebox.askyesno("Add Edge", f"Add edge from {node_name} to {other_node}?"):
                    self.graph[node_name].append(other_node)
                    self.graph[other_node].append(node_name)
                    
                    x1, y1 = self.nodes[node_name]
                    x2, y2 = self.nodes[other_node]
                    self.edges.append(self.canvas.create_line(x1, y1, x2, y2, fill="black"))
    
    def start_dfs(self):
        start_node = simpledialog.askstring("Input", "Enter the start node for DFS:")
        
        if start_node in self.graph:
            self.traversal_order.clear()
            self.dfs(start_node, set())
            
            result_text = "Traversal Order: " + " -> ".join(self.traversal_order)
            messagebox.showinfo("DFS Result", result_text)
        else:
            messagebox.showwarning("Warning", "Start node not in graph.")
    
    def dfs(self, node, visited):
        visited.add(node)
        self.traversal_order.append(node)
        
        for neighbor in self.graph[node]:
            if neighbor not in visited:
                self.dfs(neighbor, visited)
    
    def reset(self):
        self.graph.clear()
        self.nodes.clear()
        self.edges.clear()
        self.traversal_order.clear()
        self.canvas.delete("all")
        
if __name__ == "__main__":
    root = tk.Tk()
    app = DFSVisualizer(root)
    root.mainloop()

