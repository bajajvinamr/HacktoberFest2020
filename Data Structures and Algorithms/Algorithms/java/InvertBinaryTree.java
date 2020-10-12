package src;

public class InvertBinaryTree {

    Node node;

    public InvertBinaryTree(int data)
    {
        node = new Node(data);
    }

    public void insert(int data)
    {
        Node putNode = new Node(data);
        node = put(node, putNode);
    }

    private Node put(Node n, Node putNode)
    {
        if (n == null)
            return putNode;


        if (n.compareTo(putNode) < 0)
            n.left = put(n.left, putNode);
        else
            n.right = put(n.right, putNode);

        return n;
    }

    public void invert()
    {
        node = invert(node);
    }

    private Node invert(Node n)
    {
        if (n == null)
            return n;

        Node left = invert(n.left);
        Node right = invert(n.right);

        n.left = right;
        n.right = left;

        return n;
    }

    public void inorder(Node n)
    {
        if (n == null)
            return;

        inorder(n.left);
        System.out.print(n.data + " ");
        inorder(n.right);
    }

    public void preorder(Node n)
    {
        if (n == null)
            return;

        System.out.print(n.data + " ");
        preorder(n.left);
        preorder(n.right);
    }


    public void postoder(Node n)
    {
        if (n == null)
            return;

        postoder(n.left);
        postoder(n.right);
        System.out.print(n.data);
    }

    private class Node implements Comparable<Node>
    {
        int data;
        Node left;
        Node right;

        public Node(int data)
        {
            this.data = data;
            left = null;
            right = null;
        }

        public int compareTo(Node n)
        {
            if (this.data == n.data)
                return 0;
            else if (this.data < n.data)
                return -1;
            else
                return 1;
        }
    }

    public static void main(String args[])
    {
        InvertBinaryTree inv = new InvertBinaryTree(5);
        inv.insert(4);
        inv.insert(3);
        inv.insert(2);
        inv.insert(1);
        inv.insert(0);

        inv.inorder(inv.node);
        System.out.println("\n------------");
        inv.invert();
        inv.inorder(inv.node);
    }
}
