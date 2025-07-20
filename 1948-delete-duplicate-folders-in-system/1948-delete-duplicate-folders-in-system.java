class Solution {
    static class Node {
        String name;
        boolean deleted;
        Map<String, Node> children = new TreeMap<>();
        String serial;
        Node(String name) { this.name = name; }
    }

    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Node root = new Node("/");

        // 1. Build Trie
        for (List<String> path : paths) {
            Node cur = root;
            for (String folder : path) {
                cur = cur.children.computeIfAbsent(folder, k -> new Node(folder));
            }
        }

        // 2. Serialize subtrees & count
        Map<String, Integer> count = new HashMap<>();
        serialize(root, count);

        // 3. Mark duplicate subtrees
        markDeleted(root, count);

        // 4. Collect remaining paths
        List<List<String>> result = new ArrayList<>();
        dfsCollect(root, new ArrayList<>(), result);
        return result;
    }

    private String serialize(Node node, Map<String, Integer> count) {
        if (node.children.isEmpty()) {
            node.serial = "";
        } else {
            StringBuilder sb = new StringBuilder();
            for (Node child : node.children.values()) {
                sb.append("(").append(serialize(child, count)).append(")").append(child.name);
            }
            node.serial = sb.toString();
        }
        count.merge(node.serial, 1, Integer::sum);
        return node.serial;
    }

    private void markDeleted(Node node, Map<String, Integer> count) {
        for (Node child : node.children.values()) {
            markDeleted(child, count);
        }
        if (!node.serial.isEmpty() && count.getOrDefault(node.serial, 0) > 1) {
            node.deleted = true;
        }
    }

    private void dfsCollect(Node node, List<String> path, List<List<String>> result) {
        for (Node child : node.children.values()) {
            if (child.deleted) continue;
            path.add(child.name);
            result.add(new ArrayList<>(path));
            dfsCollect(child, path, result);
            path.remove(path.size() - 1);
        }
    }
}
