import tensorflow as tf
g1 = tf.Graph()
saver = tf.train.Saver()
with g1.as_default():
    g1 = tf.get_default_graph()
    session1 = tf.Session(graph=g1)
    s = tf.train.import_meta_graph("./cifar10_train/model.ckpt-49366.meta") 
    saver.restore(session1, "./cifar10_train/model.ckpt-49366")
    print session1.run(g1.get_tensor_by_name("conv1/weights:0"))[0, 0, 0, 0]

g2 = tf.Graph()
with g2.as_default():
	g2 = tf.get_default_graph()
	session2 = tf.Session(graph=g2)
	s = tf.train.import_meta_graph("./cifar10_train/model.ckpt-49366.meta") 
	s.restore(session2, "./cifar10_train/model.ckpt-49366")
	print session2.run(g2.get_tensor_by_name("conv1/weights:0"))[0, 0, 0, 0]